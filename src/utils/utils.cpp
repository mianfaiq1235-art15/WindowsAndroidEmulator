#include "utils.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>

namespace Utils
{
    bool FileExists(const std::string& path)
    {
        std::ifstream file(path);
        return file.good();
    }

    std::vector<char> ReadFileBytes(const std::string& path)
    {
        std::ifstream file(path, std::ios::binary);
        if (!file)
        {
            return {};
        }
        
        file.seekg(0, std::ios::end);
        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);
        
        std::vector<char> buffer(size);
        file.read(buffer.data(), size);
        return buffer;
    }

    bool WriteFileBytes(const std::string& path, const std::vector<char>& data)
    {
        std::ofstream file(path, std::ios::binary);
        if (!file)
        {
            return false;
        }
        
        file.write(data.data(), data.size());
        return true;
    }

    std::string ToUpper(const std::string& str)
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    std::string ToLower(const std::string& str)
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    std::vector<std::string> SplitString(const std::string& str, char delimiter)
    {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;
        
        while (std::getline(ss, token, delimiter))
        {
            tokens.push_back(token);
        }
        
        return tokens;
    }

    // Config singleton implementation
    Config& Config::GetInstance()
    {
        static Config instance;
        return instance;
    }

    bool Config::LoadConfig(const std::string& path)
    {
        std::ifstream file(path);
        if (!file)
        {
            std::cerr << "Config file not found: " << path << std::endl;
            return false;
        }
        
        std::string line;
        while (std::getline(file, line))
        {
            if (line.empty() || line[0] == '#') continue;
            
            size_t pos = line.find('=');
            if (pos != std::string::npos)
            {
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                config_data_.push_back({ key, value });
            }
        }
        
        return true;
    }

    std::string Config::GetValue(const std::string& key, const std::string& default_value)
    {
        for (const auto& pair : config_data_)
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        return default_value;
    }

    void Config::SetValue(const std::string& key, const std::string& value)
    {
        for (auto& pair : config_data_)
        {
            if (pair.first == key)
            {
                pair.second = value;
                return;
            }
        }
        config_data_.push_back({ key, value });
    }
}
