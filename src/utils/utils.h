// Utility functions header
#pragma once

#include <string>
#include <vector>

namespace Utils
{
    // File operations
    bool FileExists(const std::string& path);
    std::vector<char> ReadFileBytes(const std::string& path);
    bool WriteFileBytes(const std::string& path, const std::vector<char>& data);
    
    // String operations
    std::string ToUpper(const std::string& str);
    std::string ToLower(const std::string& str);
    std::vector<std::string> SplitString(const std::string& str, char delimiter);
    
    // Configuration
    class Config
    {
    public:
        static Config& GetInstance();
        
        bool LoadConfig(const std::string& path);
        std::string GetValue(const std::string& key, const std::string& default_value = "");
        void SetValue(const std::string& key, const std::string& value);
        
    private:
        Config() = default;
        std::vector<std::pair<std::string, std::string>> config_data_;
    };
}
