#include <iostream>
#include <sstream>

using namespace std;

class Time {
public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int hours_, int minutes_, int seconds_) : hours(hours_), minutes(minutes_), seconds(seconds_) {
        normalize();
    }

    Time operator+(const Time& right) const {
        return Time(hours + right.hours, minutes + right.minutes, seconds + right.seconds);
    }

    Time operator-(const Time& right) const {
        return Time(hours - right.hours, minutes - right.minutes, seconds - right.seconds);
    }

    bool operator==(const Time& right) const {
        return (hours == right.hours) && (minutes == right.minutes) && (seconds == right.seconds);
    }

    bool operator<(const Time& right) const {
        if (hours != right.hours) return hours < right.hours;
        if (minutes != right.minutes) return minutes < right.minutes;
        return seconds < right.seconds;
    }

    bool operator>(const Time& right) const {
        return right < *this;
    }

    friend istream& operator>>(istream& stream, Time& t) {
        string timeString;
        stream >> timeString;
        stringstream ss(timeString);
        ss >> t.hours;
        ss.ignore();
        ss >> t.minutes;
        ss.ignore();
        ss >> t.seconds;
        t.normalize();
        return stream;
    }

    friend ostream& operator<<(ostream& stream, const Time& t) {
        stream << t.hours << '.' << t.minutes << '.' << t.seconds;
        return stream;
    }

private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        } else if (seconds < 0) {
            int borrow = (abs(seconds) + 59) / 60;
            minutes -= borrow;
            seconds += borrow * 60;
        }

        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        } else if (minutes < 0) {
            int borrow = (abs(minutes) + 59) / 60;
            hours -= borrow;
            minutes += borrow * 60;
        }

        if (hours >= 24) {
            hours %= 24;
        } else if (hours < 0) {
            hours = (hours % 24 + 24) % 24; // Handle negative hours properly
        }
    }
};

int main() {
    Time t1, t2;
    cout << "Enter time in format hh.mm.ss: ";
    cin >> t1;
    cout << "You entered: " << t1 << endl;

    t2 = t1 + Time(3, 20, 40);
    cout << "Time after addition: " << t2 << endl;

    return 0;
}
