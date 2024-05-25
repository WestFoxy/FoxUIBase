#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <direct.h>
#include "FoxImgui.h"

void on_render()
{
    ImGui::SetNextWindowSize({ 500,500 }, ImGuiCond_Once);
    if (ImGui::Begin("test"))
    {
        ImGui::Columns(2);

        if (ImGui::Button("test button"))
        {

        }
        ImGui::NextColumn();

        ImGui::Text("Fox");
    }
    ImGui::End();
}

int main() 
{

    FoxImgui imgui("FoxWindow", 1280, 720, on_render, nullptr, true);

    while (imgui.isAlive())
    {
        imgui.render();
    }
}