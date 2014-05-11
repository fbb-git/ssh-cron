#ifndef INCLUDED_CRON_
#define INCLUDED_CRON_

#include <string>
#include <set>

#include <bobcat/fork>
#include <bobcat/pipe>

namespace FBB
{
    class DateTime;
}

class CronEntry;
class CronData;

class Cron: public FBB::Fork
{
    enum Leave 
    {};

    static std::string s_shell;
    static std::string s_agent;

    FBB::Pipe d_childInput;     // child reads this
    FBB::Pipe d_childOutput;    // child writes this

    CronData const &d_cronData;

    public:
        Cron(CronData const &cronData);
        void runParentProcess();

    private:
        void childRedirections()    override;
        void childProcess()         override;
        void parentProcess()        override;

        void cronLoop();
        void runCronJobs();
        bool call(FBB::DateTime const &now, CronEntry const &entry);
        void execute(CronEntry const &entry);
        static bool specified(size_t value, std::set<size_t> const &request);
};
        
#endif








