#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace Util
{
    std::string GetCurrentTime(std::string format = "%Y-%m-%d %H:%M:%S");
    void Log(const std::string &message);
    int LogError(const std::string &errorMessage);
}
