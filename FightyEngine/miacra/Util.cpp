#include "Util.h"

namespace Util
{
    std::string GetCurrentTime(std::string &format)
    {
        if (format == nullptr)
            return std::string();
        if (format == "default")
            format = "%Y-%m-%d %H:%M:%S";

        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm *now_tm = std::localtime(&now_c);
        std::ostringstream s_stream;
        s_stream << std::put_time(now_tm, format.c_str());

        return s_stream.str();
    }

    void Log(const std::string &message)
    {
        std::string time = GetCurrentTime("default");
        if (!time.empty())
        {
            std::cout << "[INFO] | " << time << "] " << message << std::endl;
        }
        else
        {
            LogError("Util::Log() function error");
        }
    }

    int LogError(const std::string &errorMessage)
    {
        std::string time = GetCurrentTime("default");
        if (!time.empty())
        {
            std::cerr << "[ERROR | " << time << "] " << errorMessage << std::endl;
        }
        return 1;
    }
}
