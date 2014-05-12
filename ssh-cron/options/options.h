#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

namespace FBB
{
    class ArgConfig;
}

class Options
{
    FBB::ArgConfig &d_arg;

    static Options *s_options;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

    private:
        Options();
};

        
#endif
