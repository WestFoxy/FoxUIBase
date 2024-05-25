#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <string>

#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void window_size_callback(GLFWwindow* window, int width, int height);
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class FoxImgui
{
public:
	using UserImguiCallback = void();
	using UserRenderCallback = void();
	
    FoxImgui() = delete;
    ~FoxImgui();
    FoxImgui::FoxImgui(std::string title = "TestFoxWindow",
        unsigned int width = 1280, unsigned int height = 720,
        UserImguiCallback* imgui_callback = nullptr,
        UserRenderCallback* render_callback = nullptr,
        bool hide_terminal = false);

    bool isAlive();
    void render(bool isResizing = false);

    int window_width, window_height;
    std::string window_name;
private:
	UserImguiCallback* user_imgui = nullptr;
	UserRenderCallback* user_render = nullptr;

    GLFWwindow* window = nullptr;

    void ImguiSetDefaultStyle();
};

