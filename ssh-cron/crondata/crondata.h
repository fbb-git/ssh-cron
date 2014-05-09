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

        void setMinutes(std::set<int> const &minutes);
        void setHours(std::set<int> const &minutes);
        void setDayOfMonth(std::set<int> const &minutes);
        void setMonthOfYear(std::set<int> const &minutes);
        void setDayOfWeek(std::set<int> const &minutes);
    private:
};
        
#endif
