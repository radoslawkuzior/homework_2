#ifndef CLASS_H
#define CLASS_H

#endif // CLASS_H


#include <iostream>

class Time {
private:
    int seconds;
public:
    Time(int sec = 0) {
        seconds = sec;
    }

    Time(int h, int m, int s) {
        seconds = (h * 3600) + (m * 60) + s;
    }

    Time operator+(const Time &t) const {
        return Time(seconds + t.seconds);
    }

    Time operator-(const Time &t) const {
        return Time(seconds - t.seconds);
    }

    Time operator*(int num) const {
        return Time(seconds * num);
    }

    operator int() const {
        return seconds;
    }

    friend std::ostream &operator<<(std::ostream &out, const Time &t) {
        int h = t.seconds / 3600;
        int m = (t.seconds % 3600) / 60;
        int s = t.seconds % 60;

        if (h < 10) out << "0";
        out << h << "m:";

        if (m < 10) out << "0";
        out << m << "m:";

        if (s < 10) out << "0";
        out << s << "s";

        return out;
    }

    friend std::istream &operator>>(std::istream &in, Time &t) {
        int h, m, s;
        char c1, c2;
        in >> h >> c1 >> m >> c2 >> s;

        if (c1 == 'h' && c2 == 'm') {
            t = Time(h, m, s);
        }
        return in;
    }
};
