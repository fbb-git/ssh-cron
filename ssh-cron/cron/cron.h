#ifndef INCLUDED_CRON_
#define INCLUDED_CRON_

#include <string>

#include <bobcat/fork>
#include <bobcat/pipe>

class Cron: public FBB::Fork
{
    enum Leave 
    {};

    static std::string s_shell;
    static std::string s_agent;

    FBB::Pipe d_childInput;     // child reads this
    FBB::Pipe d_childOutput;    // child writes this

    public:
        Cron();

    private:
        void childRedirections()    override;
        void childProcess()         override;
        void parentProcess()        override;
};
        
#endif








