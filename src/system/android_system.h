// Android system emulation header
#pragma once

#include <cstdint>
#include <string>

class AndroidSystem
{
public:
    AndroidSystem();
    ~AndroidSystem();

    bool Initialize();
    void Shutdown();
    
    bool StartApp(const std::string& package_name);
    bool StopApp(const std::string& package_name);
    bool InstallPackage(const std::string& apk_path);
    
    const char* GetAndroidVersion() const { return "13.0"; }
    bool IsRunning() const { return is_running_; }

private:
    bool is_running_;
    uint32_t allocated_ram_;
};
