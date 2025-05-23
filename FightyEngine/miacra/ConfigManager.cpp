#include "ConfigManager.h"

using std::string;
using std::unordered_map;
using std::filesystem::path;

namespace ConfigManager
{
    static unordered_map<string, string> configValues;

    bool LoadConfig()
    {
        path config_file = path("config") / "cfg.ini";
        configValues.clear();

        auto handler = [](void *user, const char *section, const char *name, const char *value) -> int
        {
            string key = string(section) + "." + string(name);
            string val = string(value);
            configValues[key] = val;

            Util::Log("[Config] " + key + " = " + val);
            return 1;
        };

        if (ini_parse(config_file.string().c_str(), handler, nullptr) < 0)
        {
            Util::LogError("Failed to load INI file: " + config_file.string());
            return false;
        }
        return true;
    }

    bool GetBool(const string &section, const string &name, bool defaultValue)
    {
        string key = section + "." + name;
        auto it = configValues.find(key);
        if (it != configValues.end())
        {
            string val = it->second;
            return val == "true" || val == "1";
        }
        return defaultValue;
    }

    string GetString(const string &section, const string &name, const string &defaultValue)
    {
        string key = section + "." + name;
        auto it = configValues.find(key);
        return (it != configValues.end()) ? it->second : defaultValue;
    }
}
