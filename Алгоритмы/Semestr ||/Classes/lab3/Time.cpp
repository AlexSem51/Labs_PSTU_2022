#include "Time.h"

Time::Time() {
    seconds = 0;
    minutes = 0;
}

Time::Time(int m, int s) {
    seconds = s;
    minutes = m;
}

Time::Time(Time &t) {
    seconds = t.seconds;
    minutes = t.minutes;
}

Time &Time::operator=(Time &t) {
    minutes = t.minutes;
    seconds = t.seconds;
    return *this;
}

Time &Time::operator+(Time &t) {
    int tmp = (60 * minutes + seconds) + (60 * t.minutes + t.seconds);
    minutes = tmp / 60;
    seconds = tmp % 60;
    return *this;
}
