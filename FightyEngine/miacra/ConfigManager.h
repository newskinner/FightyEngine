#pragma once

#include "../miacra/Util.h"
#include "../../include/inih/ini.h"
#include <unordered_map>
#include <filesystem>
#include <string>
#include <fstream>

namespace ConfigManager
{
    bool LoadConfig();

    bool GetBool(const std::string &section, const std::string &name, bool defaultValue = false) const;
    std::string GetString(const std::string &section, const std::string &name, const std::string &defaultValue = "") const;

    void SetValue(const std::string &section, const std::string &name, const std::string &newValue);

    void SaveConfig();
}
