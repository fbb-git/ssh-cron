#ifndef INCLUDED_CRON_
#define INCLUDED_CRON_

#include <set>
#include <iosfwd>

#include <bobcat/fork>
#include <bobcat/pipe>
#include <bobcat/selector>
#include <bobcat/signal>

namespace FBB
{
    class DateTime;
}

class CronEntry;
class CronData;

class Cron: public FBB::Fork, public FBB::SignalHandler
{
    enum Leave 
    {};

    enum Action         // TERMINATE is implemented as a thrown exception 
    {
        LOOP,
        LIST,
        RELOAD
    };

    volatile Action d_action = LOOP;
    
    std::ofstream &d_stdMsg;
    CronData const &d_cronData;

    FBB::Pipe d_childInput;     // child reads this
    FBB::Pipe d_childOutput;    // child writes this


    bool d_sendCommands;
    FBB::Selector d_selector;
    
    std::istream *d_fromChild = 0;  // not allocated, set by parentProcess
    std::ostream *d_toChild = 0;

    static std::string s_agent;

    public:
        Cron(std::ofstream &stdMsg, CronData const &cronData);
        void runParentProcess();

    private:
        void childRedirections()    override;
        void childProcess()         override;
        void parentProcess()        override;
        void signalHandler(size_t signum)   override;

        void sendCommand(std::string line);
        void cronLoop();
        void runCronJobs();
        bool call(FBB::DateTime const &now, CronEntry const &entry);
        void execute(CronEntry const &entry);
        static bool specified(size_t value, std::set<size_t> const &request);
};
        
#endif








