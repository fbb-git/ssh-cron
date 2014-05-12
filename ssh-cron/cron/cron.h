#ifndef INCLUDED_CRON_
#define INCLUDED_CRON_

#include <set>
#include <fstream>

#include <bobcat/fork>
#include <bobcat/pipe>
#include <bobcat/selector>

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

    bool d_sendCommands;
    FBB::Selector d_selector;
    
    std::ofstream d_log;

    std::istream *d_fromChild = 0;  // not allocated, set by parentProcess
    std::ostream *d_toChild = 0;

    public:
        Cron(CronData const &cronData);
        void runParentProcess();

    private:
        void childRedirections()    override;
        void childProcess()         override;
        void parentProcess()        override;

        void sendCommand(std::string line);
        void cronLoop();
        void runCronJobs();
        bool call(FBB::DateTime const &now, CronEntry const &entry);
        void execute(CronEntry const &entry);
        static bool specified(size_t value, std::set<size_t> const &request);
};
        
#endif








