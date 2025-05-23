#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace Util
{
    /* "default" can be passed as an argument, it's an alias for "%Y-%m-%d %H:%M:%S" */
    std::string GetCurrentTime(std::string &format);
    void Log(const std::string &message);
    int LogError(const std::string &errorMessage);
}