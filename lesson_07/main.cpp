#include "logger.h"

int main()
{
    Logger log("logfile.txt");

    log.write_log("Hello, world!");
    log.write_log("This is homework #", 7);
    log.write_log("The value of e is ", 2.7182);

    return 0;
}