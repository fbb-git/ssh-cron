#ifndef INCLUDED_CRON_
#define INCLUDED_CRON_

#include <set>
#include <iosfwd>

#include <bobcat/fork>
#include <bobcat/pipe>

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

        Options &d_options;
        CronData const &d_cronData;
    
        FBB::Pipe d_childInput;     // child reads this
        
        std::ostream *d_toChild = 0;

        volatile bool d_run = true;     // set to false by stop

        static std::string s_agent;
    
    public:
        Cron(CronData const &cronData);
        void runParentProcess();
        void stop(size_t signal);

    private:
        void childRedirections()    override;
        void childProcess()         override;
        void parentProcess()        override;

        void defineRunFunction();
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








