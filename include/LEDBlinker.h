/*
  Author: Tobias Grundtvig
*/

#ifndef LEDBlinker_h
#define LEDBlinker_h

#include <Arduino.h>


class LEDBlinker
{
public:
    LEDBlinker(const uint8_t ledPin, bool ledON, uint32_t onMS, uint32_t offMS, uint32_t pauseMS);
    void update(unsigned long curTimeMS);
    void startBlink(uint16 count);
    void stopBlink();
    bool isBlinking();
private:
    uint8_t _ledPin;
    uint32_t _onMS;
    uint32_t _offMS;
    uint32_t _pauseMS;
    uint16_t _count;
    uint16_t _blinksLeft;
    unsigned long _lastChange;
    bool _ledValue;
    bool _ledON;

};

#endif