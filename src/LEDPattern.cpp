/*
  Author: Tobias Grundtvig
*/

#include <Arduino.h>
#include "LEDBlinker.h"

LEDBlinker::LEDBlinker(const uint8_t ledPin, bool ledON, uint32_t onMS, uint32_t offMS, uint32_t pauseMS)
{
    _ledPin = ledPin;
    _onMS = onMS;
    _offMS = offMS;
    _pauseMS = pauseMS;
    _ledON = ledON;
    _ledValue = !ledON;
    _lastChange = 0;
    pinMode(ledPin, OUTPUT);
    digitalWrite(_ledPin, _ledValue);
}

void LEDBlinker::update(unsigned long curTime)
{
    if(_count == 0 && _blinksLeft == 0)
    {
        return;
    }
    if(_ledValue == _ledON)
    {
        if(curTime < _lastChange + _onMS)
        {
            return;
        }
        _lastChange = curTime;
        _ledValue = !_ledON;
        digitalWrite(_ledPin, _ledValue);
        --_blinksLeft;
        return;
    }
    if(_blinksLeft == 0)
    {
        if(curTime < _lastChange + _pauseMS)
        {
            return;
        }
        _blinksLeft = _count;       
    }
    else
    {
        if(curTime < _lastChange + _offMS)
        {
            return;
        }
    }
    _lastChange = curTime;
    _ledValue = _ledON;
    digitalWrite(_ledPin, _ledValue);
}

void LEDBlinker::startBlink(uint16 count)
{
    _count = count;
}

void LEDBlinker::stopBlink()
{
    _count = 0;
}

bool LEDBlinker::isBlinking()
{
    return _count > 0;
}