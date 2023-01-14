﻿#include "EngineAppInstance.h"
#include <Apatite/EngineAppInstance.h>
#include <Apatite/Application.h>
#include <Apatite/World.h>
#include <Apatite/Logger.h>
#include <Apatite/Private/SystemInterface.h>
#include <Apatite/Private/RenderInterface.h>
#include <filesystem>
#include <Apatite/ImGuiImpl.h>
#include <Apatite/Private/InputInterface.h>

namespace apatite
{
    using namespace detail;
    const char* EngineAppInstance::AppType()
    {
        return "engine";
    }

    static bool _RequestQuit()
    {
        //请求关闭程序
        return Application::inst()->RequestQuitEvents.IsValidReturnInvoke();
    }

    static void _quitting()
    {
        Logger::Log (LogLevel::Info, "engine application is quitting");

        //通知程序即将关闭
        Application::inst()->QuittingEvents.Invoke();
    }

    void EngineAppInstance::OnInitialize(string_view title, Vector2f size)
    {
        Logger::Log(LogLevel::Info, "application initialize");
        SystemInterface::InitializeWindow(title, (int)size.x, (int)size.y);
        SystemInterface::SetRequestQuitCallBack(_RequestQuit);
        SystemInterface::SetQuitCallBack(_quitting);
        RenderInterface::SetViewport(0, 0, (int)size.x, (int)size.y);
        ImGui_Engine_Initialize();
        World::Reset(new World);
    }

    void EngineAppInstance::OnTerminate()
    {
        ImGui_Engine_Terminate();
        World::Reset(nullptr);
    }

    void EngineAppInstance::OnTick(float dt)
    {
        auto bgc = LinearColorf{ 0.2f, 0.2f ,0.2f, 0.2 };
        RenderInterface::Clear(bgc.r, bgc.g, bgc.b, bgc.a);
        ImGui_Engine_NewFrame();

        World::Current()->Tick(dt);

        ImGui_Engine_EndFrame();

        RenderInterface::Render();
        SystemInterface::PollEvents();
        InputInterface::PollEvents();
    }
    bool EngineAppInstance::IsQuit()
    {
        return SystemInterface::GetIsQuit();
    }
    void EngineAppInstance::RequestQuit()
    {
        SystemInterface::RequestQuitEvents();
    }

    Vector2f EngineAppInstance::GetOutputScreenSize()
    {
        int32_t x, y;
        detail::RenderInterface::GetDefaultBufferViewport(&x, &y);
        return Vector2f(x, y);
    }
    void EngineAppInstance::SetOutputScreenSize(Vector2f size)
    {
        detail::RenderInterface::SetViewport(0, 0, (int)size.x, (int)size.y);
    }

    string EngineAppInstance::GetTitle()
    {
        return string();
    }
    void EngineAppInstance::SetTitle(string_view title)
    {
    }
    string EngineAppInstance::AppRootDir()
    {
        return StringUtil::StringCast(std::filesystem::current_path().generic_u8string());
    }

}