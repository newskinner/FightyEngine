#pragma once

#include "../miacra/Util.h"
#include "../../include/inih/ini.h"
#include <unordered_map>
#include <filesystem>
#include <string>

using std::filesystem::path;

namespace ConfigManager
{
    bool LoadConfig();

    bool GetBool(const std::string &section, const std::string &name, bool defaultValue = false);
    std::string GetString(const std::string &section, const std::string &name, const std::string &defaultValue = "");
}
