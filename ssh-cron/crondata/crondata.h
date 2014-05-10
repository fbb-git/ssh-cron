#ifndef INCLUDED_CRONDATA_
#define INCLUDED_CRONDATA_

#include <string>
#include <set>
#include <vector>

class CronData
{
    struct Entry
    {
        std::set<size_t>    d_minutes;
        std::set<size_t>    d_hours;
        std::set<size_t>    d_dayOfMonth;
        std::set<size_t>    d_monthOfYear;
        std::set<size_t>    d_dayOfWeek;
    
        std::string         d_command;
    };
    std::vector<Entry> d_entry;

    std::set<size_t> d_wip;
    std::vector<std::string> d_names;
    std::string d_command;

    size_t d_lineNr;
    bool d_all = false;

    public:
        CronData();

        void addNr(size_t nr);
        void addRange(size_t first, size_t last, size_t step);
        void setAll(size_t step);
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

        void outOfRange(size_t nr) const;

};
        
#endif
