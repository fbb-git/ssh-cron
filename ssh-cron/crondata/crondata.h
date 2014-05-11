#ifndef INCLUDED_CRONDATA_
#define INCLUDED_CRONDATA_

#include <iosfwd>
#include <string>
#include <set>
#include <vector>

class CronData
{
    struct Entry
    {
        size_t              nSettings  = 0;
        std::set<size_t>    minutes;
        std::set<size_t>    hours;
        std::set<size_t>    dayOfMonth;
        std::set<size_t>    monthOfYear;
        std::set<size_t>    dayOfWeek;
    
        std::string         command;
    };
    friend std::ostream &operator<<(std::ostream &out, Entry const &entry);

    std::vector<std::string> d_environment;
    std::vector<Entry> d_entry;

    Entry d_next;

    std::string d_entryName;
    size_t d_entryBegin = 0;
    size_t d_entryEnd = 60;


    std::set<size_t> d_wip;

    std::vector<std::string> d_names;

    size_t d_lineNr;
    bool d_all = false;

    enum
    {
        STAR = 100                  // * used to specify time
    };

    static size_t s_values[60];
    static char const *const s_month[12];
    static char const *const s_day[7];

    public:
        CronData();

        void addNr(size_t nr);
        void addRange(size_t first, size_t last, size_t step);
        void setAll(size_t step);
        void addName(std::string const &str);
        void setCommand(std::string const &command);
        void process();
        void reset(size_t lineNr = 0);  // 0 means: do not update lineNr

        void setMinutes();
        void setHours();
        void setDayOfMonth();
        void setMonthOfYear();
        void setDayOfWeek();

        void setEnvVar(std::string const &var, std::string const &value);

        size_t lineNr() const;

    private:
        void assign(std::set<size_t> &dest);
        void assign(std::set<size_t> &dest, char const *const *names,
                    bool allowEnd = false);
        void invalidRange(size_t first, size_t last) const;
        void outOfRange(size_t nr);
        void addCronCommand();

        static void showSet(std::ostream &out, std::set<size_t> const &nrSet);
};

inline size_t CronData::lineNr() const
{
    return d_lineNr;
}
        
#endif
