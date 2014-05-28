#ifndef INCLUDED_CRON_
#define INCLUDED_CRON_

#include <set>
#include <iosfwd>

#include <bobcat/fork>
#include <bobcat/pipe>
#include <bobcat/selector>

namespace FBB
{
    class DateTime;
}

class CronEntry;
class CronData;
class Options;

struct Cron: public FBB::Fork
{
    enum Function
    {
        TERMINATE,
        LIST,
        RELOAD,
        DONE
    };

    private:
        enum EndOfRun
        {};
    
        enum Leave 
        {};
    
        Options &d_options;
        CronData const &d_cronData;
    
        FBB::Pipe d_childInput;     // child reads this
        FBB::Pipe d_childOutput;    // child writes this
    
    
        FBB::Selector d_selector;
        
        std::istream *d_fromChild = 0;  // not allocated, set by parentProcess
        std::ostream *d_toChild = 0;

        volatile bool d_run = true;     // set to false by requestHandler
        volatile bool d_interrupted = false;

        static std::string s_agent;
    
    public:
        Cron(CronData const &cronData);
        void runParentProcess();
        void stop(size_t signal);

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

        static void requestHandler(Cron *cron);
        void handleRequests();
};

#endif








