#ifndef INCLUDED_CRONDATA_
#define INCLUDED_CRONDATA_

#include <string>
#include <set>
#include <vector>

class CronData
{
    struct Entry
    {
        std::set<int>   d_minutes;
        std::set<int>   d_hours;
        std::set<int>   d_dayOfMonth;
        std::set<int>   d_monthOfYear;
        std::set<int>   d_dayOfWeek;

        std::string     d_command;
    };

    std::vector<Entry> d_entry;

    public:
        CronData();

        void addNr(int nr);
        void addRange(int first, int last, int step);
        void setAll(int step);
        void addName(std::string const &str);
        void setCommand(std::string const &command);
        void process();
        void reset(size_t lineNr);

        void setMinutes();
        void setHours();
        void setDayOfMonth();
        void setMonthOfYear();
        void setDayOfWeek();
        
    private:
};
        
#endif
