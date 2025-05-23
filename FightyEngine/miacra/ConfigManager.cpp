#include "ConfigManager.h"

using std::string;
using std::unordered_map;
using std::filesystem::path;

namespace ConfigManager
{
    static unordered_map<string, string> configValues;
    const path config_file = path("config") / "cfg.ini";

    bool LoadConfig()
    {
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

    void SetValue(const string &section, const string &name, const string &newValue)
    {
        string key = section + "." + name;
        configValues[key] = newValue;
        Util::Log("[Config] Set " + key + " = " + newValue);
        SaveConfig();
    }

    void SaveConfig()
    {
        std::unordered_map<string, unordered_map<string, string>> sectioned;
        for (const auto &kv : configValues)
        {
            size_t dotPos = kv.first.find('.');
            if (dotPos != string::npos)
            {
                string section = kv.first.substr(0, dotPos);
                string name = kv.first.substr(dotPos + 1);
                sectioned[section][name] = kv.second;
            }
        }

        std::ofstream file(config_file);
        if (!file.is_open())
        {
            Util::LogError("Failed to save INI file: " + config_file.string());
            return;
        }

        for (const auto &[section, entries] : sectioned)
        {
            file << "[" << section << "]\n";
            for (const auto &[name, value] : entries)
            {
                file << name << "=" << value << "\n";
            }
            file << "\n";
        }

        Util::Log("[Config] Saved config to " + config_file.string());
    }
}
