// DirectX 11 graphics rendering header
#pragma once

#include <d3d11.h>
#include <wrl.h>
#include <cstdint>

using Microsoft::WRL::ComPtr;

class GraphicsEngine
{
public:
    GraphicsEngine();
    ~GraphicsEngine();

    bool Initialize(uint32_t width, uint32_t height);
    void Shutdown();
    void BeginFrame();
    void EndFrame();
    void SetResolution(uint32_t width, uint32_t height);

    uint32_t GetWidth() const { return screen_width_; }
    uint32_t GetHeight() const { return screen_height_; }
    bool IsInitialized() const { return device_ != nullptr; }

private:
    ComPtr<ID3D11Device> device_;
    ComPtr<ID3D11DeviceContext> context_;
    ComPtr<IDXGISwapChain> swap_chain_;
    ComPtr<ID3D11RenderTargetView> render_target_;
    
    uint32_t screen_width_;
    uint32_t screen_height_;
};
