#include "graphics.h"
#include <iostream>

GraphicsEngine::GraphicsEngine()
    : screen_width_(1280),
      screen_height_(720)
{
}

GraphicsEngine::~GraphicsEngine()
{
    Shutdown();
}

bool GraphicsEngine::Initialize(uint32_t width, uint32_t height)
{
    screen_width_ = width;
    screen_height_ = height;
    
    std::cout << "Initializing graphics engine..." << std::endl;
    std::cout << "Resolution: " << width << "x" << height << std::endl;
    std::cout << "Graphics API: DirectX 11" << std::endl;
    
    // DirectX initialization would go here
    return true;
}

void GraphicsEngine::Shutdown()
{
    if (device_)
    {
        std::cout << "Shutting down graphics engine..." << std::endl;
        device_.Reset();
        context_.Reset();
        swap_chain_.Reset();
        render_target_.Reset();
    }
}

void GraphicsEngine::BeginFrame()
{
    if (context_ && render_target_)
    {
        float clear_color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        context_->ClearRenderTargetView(render_target_.Get(), clear_color);
    }
}

void GraphicsEngine::EndFrame()
{
    if (swap_chain_)
    {
        swap_chain_->Present(1, 0);
    }
}

void GraphicsEngine::SetResolution(uint32_t width, uint32_t height)
{
    screen_width_ = width;
    screen_height_ = height;
    std::cout << "Graphics resolution set to " << width << "x" << height << std::endl;
}
