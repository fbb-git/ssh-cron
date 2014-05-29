#include "cron.ih"

void Cron::defineRunFunction()
{
    *d_toChild << R"(
_run_()
{
    out=`eval $* 2>&1`
    [ "$out" == "" ] || echo "$out" | 
        )" << d_options.mailer() << R"(
}
)";

    imsg << "defined the run function" << endl;
}
