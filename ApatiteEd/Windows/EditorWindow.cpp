#include <ApatiteEd/Windows/EditorWindow.h>
#include <ApatiteEd/Menus/Menu.h>
#include <ApatiteEd/Windows/EditorWindowManager.h>
#include <ApatiteEd/Menus/MenuEntry.h>

namespace apatiteed
{
    string_view EditorWindow::GetWindowName() const
    {
        return "editor window";
    }

    void EditorWindow::DrawImGui()
    {
        ImGui::Begin(GetWindowName().data(), &this->is_opened, GetGuiWindowFlags());
        if (this->is_opened)
        {
            this->OnDrawImGui();
        }
        else
        {
            this->is_opened = true;
            this->Close();
        }

        ImGui::End();
    }

    void EditorWindow::OnDrawImGui()
    {

    }

    bool EditorWindow::Open()
    {
        if (this->is_opened) return true;
        
        if (!EditorWindowManager::RegisterWindow(self()))
        {
            return false;
        }
        this->is_opened = true;
        this->OnOpen();
        return true;
    }
    void EditorWindow::Close()
    {
        if (!this->is_opened) return;
        this->is_opened = false;
        this->OnClose();
        EditorWindowManager::UnRegisterWindow(self());
    }

    static int _NewId()
    {
        static int id = 0;
        return ++id;
    }

    EditorWindow::EditorWindow() : window_id_(_NewId())
    {

    }
}