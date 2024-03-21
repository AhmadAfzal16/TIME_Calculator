#ifndef TIME_H
#define TIME_H
using namespace std;
// Time abstract data type definition
class Time
{
public:
    // set functions
    Time(int = 0, int = 0, int = 0);
    void setTime(int, int, int);  // set hour, minute, second
    void setHour(int);            // set hour (after validation)
    void setMinute(int);          // set minute (after validation)
    void setSecond(int);          // set second (after validation)

    // get functions
    int getHour();  // return hour
    int getMinute(); // return minute
    int getSecond(); // return second

    void printUniversal(); // output time in universal-time format
    void printStandard();  // output time in standard-time format
    void tick();
    void writetoFile();
    void findHighestTimeFromFile();

private:
    int hour;    // 0 - 23 (24-hour clock format)
    int minute;  // 0 - 59
    int second;  // 0 - 59
}; // end class Time

#endif // TIME_H
