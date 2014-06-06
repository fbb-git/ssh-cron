#include "cron.ih"

void Cron::defineRunFunction()
{
    std::string const &mailer = d_options.mailer();

    if (mailer.empty())
        *d_toChild << R"(
_run_()
{
    eval $* 2>&1 > /dev/null
}
)";
    else
        *d_toChild << R"(
_run_()
{
    out=`eval $* 2>&1`
    [ "$out" == "" ] || echo "$out" | 
        )" << mailer << R"(
}
)";

    idmsg() << "defined _run_()" << endl;
}
