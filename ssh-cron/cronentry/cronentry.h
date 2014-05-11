#ifndef INCLUDED_CRONENTRY_
#define INCLUDED_CRONENTRY_

#include <iosfwd>
#include <set>
#include <string>

class CronEntry
{
    friend std::ostream &operator<<(std::ostream &out, CronEntry const &entry);

    size_t              d_nSettings  = 0;
    std::set<size_t>    d_minutes;
    std::set<size_t>    d_hours;
    std::set<size_t>    d_dayOfMonth;
    std::set<size_t>    d_monthOfYear;
    std::set<size_t>    d_dayOfWeek;

    std::string         d_command;

    public:
        enum
        {
            STAR = 100                  // * used to specify time
        };

        void setNsettings(size_t nSettings);
        void setCommand(std::string const &src);

        void setMinutes(std::set<size_t> &&src);
        void setHours(std::set<size_t> &&src);
        void setDayOfMonth(std::set<size_t> &&src);
        void setMonthOfYear(std::set<size_t> &&src);
        void setDayOfWeek(std::set<size_t> &&src);

        size_t nSettings() const;
        std::string const &command() const;

        std::set<size_t> const &minutes() const;
        std::set<size_t> const &hours() const;
        std::set<size_t> const &dayOfMonth() const;
        std::set<size_t> const &monthOfYear() const;
        std::set<size_t> const &dayOfWeek() const;

    private:
        static void showSet(std::ostream &out, std::set<size_t> const &nrSet);
};

inline void CronEntry::setNsettings(size_t nSettings)
{
    d_nSettings = nSettings;
}

inline void CronEntry::setCommand(std::string const &src)
{
    d_command = src;
}

inline void CronEntry::setMinutes(std::set<size_t> &&src)
{
    d_minutes = std::move(src);
}

inline void CronEntry::setHours(std::set<size_t> &&src)
{
    d_hours = std::move(src);
}

inline void CronEntry::setDayOfMonth(std::set<size_t> &&src)
{
    d_dayOfMonth = std::move(src);
}

inline void CronEntry::setMonthOfYear(std::set<size_t> &&src)
{
    d_monthOfYear = std::move(src);
}

inline void CronEntry::setDayOfWeek(std::set<size_t> &&src)
{
    d_dayOfWeek = std::move(src);
}

inline size_t CronEntry::nSettings() const
{
    return d_nSettings;
}

inline std::string const &CronEntry::command() const
{
    return d_command;
}

inline std::set<size_t> const &CronEntry::minutes() const
{
    return d_minutes;
}

inline std::set<size_t> const &CronEntry::hours() const
{
    return d_hours;
}

inline std::set<size_t> const &CronEntry::dayOfMonth() const
{
    return d_dayOfMonth;
}

inline std::set<size_t> const &CronEntry::monthOfYear() const
{
    return d_monthOfYear;
}

inline std::set<size_t> const &CronEntry::dayOfWeek() const
{
    return d_dayOfWeek;
}


#endif







