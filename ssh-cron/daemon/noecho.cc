#include "daemon.ih"

void Daemon::noEcho() const
{
    struct termios tty; 
    int fd = open("/dev/tty", O_RDONLY);
    
    tcgetattr(fd, &tty);
    tty.c_lflag &= ~ECHO;

    tcsetattr(fd, TCSANOW, &tty);
}
