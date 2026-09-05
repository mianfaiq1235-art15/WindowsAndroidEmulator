// Core emulator engine header
#pragma once

#include <cstdint>
#include <memory>
#include <vector>

class Emulator
{
public:
    Emulator();
    ~Emulator();

    bool Initialize();
    void Shutdown();
    void Update(float deltaTime);
    void Render();

    // Configuration
    void SetRAM(uint32_t megabytes);
    void SetCPUCores(uint32_t cores);
    void SetResolution(uint32_t width, uint32_t height);
    void SetFPS(uint32_t fps);

    uint32_t GetRAM() const { return ram_mb_; }
    uint32_t GetCPUCores() const { return cpu_cores_; }
    void GetResolution(uint32_t& width, uint32_t& height) const;
    uint32_t GetFPS() const { return target_fps_; }

    bool LoadAPK(const char* apk_path);
    bool InstallAPK(const char* package_name);

private:
    uint32_t ram_mb_;
    uint32_t cpu_cores_;
    uint32_t screen_width_;
    uint32_t screen_height_;
    uint32_t target_fps_;
    bool is_running_;
};
