#ifndef INCLUDED_CRONDATA_
#define INCLUDED_CRONDATA_

#include <string>
#include <set>
#include <vector>

#include "../cronentry/cronentry.h"

class CronData
{
    friend 
        std::ostream &operator<<(std::ostream &out, CronData const &cronData);

    std::vector<std::string> d_environment;
    std::vector<CronEntry> d_cronEntries;
    size_t d_lastSize = 0;

    CronEntry d_next;

    std::string d_entryName;
    size_t d_entryBegin = 0;
    size_t d_entryEnd = 60;

    std::set<size_t> d_wip;

    std::vector<std::string> d_names;   // names used for time specifications
                                        // at a cron-job line

    size_t d_lineNr;
    bool d_all = false;
    bool  d_info = true;

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

        void messages(bool on = true);

        void setMinutes();
        void setHours();
        void setDayOfMonth();
        void setMonthOfYear();
        void setDayOfWeek();

        void setEnvVar(std::string const &var, std::string const &value);

        size_t lineNr() const;
        size_t size() const;

        std::vector<CronEntry> const &cronEntries() const;
        CronEntry const &operator[](size_t index) const;

        std::vector<std::string> const &environment() const;

    private:
        std::set<size_t> assign();
        std::set<size_t> assign(char const *const *names,
                                                    bool allowEnd = false);

        void invalidRange(size_t first, size_t last) const;
        void outOfRange(size_t nr);
        void addCronCommand();
            
        std::ostream &insert(std::ostream &out) const;
};

inline size_t CronData::lineNr() const
{
    return d_lineNr;
}

inline void CronData::messages(bool onOff)
{
    d_info = onOff;
}

inline CronEntry const &CronData::operator[](size_t index) const
{
    return d_cronEntries[index];
}

inline std::vector<CronEntry> const &CronData::cronEntries() const
{
    return d_cronEntries;
}

inline size_t CronData::size() const
{
    return d_cronEntries.size();
}

inline std::vector<std::string> const &CronData::environment() const
{
    return d_environment;
}

inline std::ostream &operator<<(std::ostream &out, CronData const &cronData)
{
    return cronData.insert(out);
}
        
#endif
