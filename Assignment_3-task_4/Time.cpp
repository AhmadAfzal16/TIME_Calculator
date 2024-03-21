#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include<string>
#include "Time.h"
using namespace std;
Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}
void Time::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}
void Time::setHour(int h)
{
    if (h >= 0 && h < 24) {
        hour = h;
    }
    else {
        throw invalid_argument("hour must be 0-23");
    }
}

void Time::setMinute(int m)
{
    if (m >= 0 && m < 60) {
        minute = m;
    }

    else {
        throw invalid_argument("minute must be 0-59");
    }
}

void Time::setSecond(int s)
{
    if (s >= 0 && s < 60) {
        second = s;
    }

    else {
        throw invalid_argument("second must be 0-59");
    }

}

int Time::getHour()
{
    return hour;
}

int Time::getMinute()
{
    return minute;
}
int Time::getSecond()
{
    return second;
}
void Time::printUniversal()
{
    std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
        << std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond();
}
void Time::printStandard()
{
    std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << std::setfill('0') << std::setw(2) << getMinute()
        << ":" << std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}
void Time::tick() {
    if (++second == 60)
    {
        second = 0;
        if (++minute == 60)
        {
            minute = 0;
            if (++hour == 24)
                hour = 0;
        }
    }
}

void Time::writetoFile() {
    ofstream fout;
    fout.open("Time.txt", ios::app);
    fout << hour << ":" << minute << ":" << second << endl;
    fout.close();
}
void Time::findHighestTimeFromFile() {
    ifstream fin;
    fin.open("Time.txt");

    if (!fin) {
        cout << "Unable to open file"<< endl;
        return;
    }

    Time highestTime(0, 0, 0); 

    string line;
    while (fin>>line) {
        int h, m, s;
        char delimiter;
        if (fin>> h >> delimiter >> m >> delimiter >> s) {
            Time currentTime(h, m, s);
            if (currentTime.getHour() > highestTime.getHour() ||(currentTime.getHour() == highestTime.getHour() &&
                    currentTime.getMinute() > highestTime.getMinute()) ||(currentTime.getHour() == highestTime.getHour() &&
                    currentTime.getMinute() == highestTime.getMinute() &&currentTime.getSecond() > highestTime.getSecond())) {
                highestTime = currentTime;
            }
        }
    }
    cout << "\nThe highest time in File is: " << endl;
    highestTime.printUniversal();
    fin.close(); 

}