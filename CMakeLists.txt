cmake_minimum_required(VERSION 3.6)
project(FoxUIBase)

option(FOX_IMGUI_DEMO "Compile ImGui demo" OFF) #OFF by default
option(FOX_IMGUI_IMPLOT "Compile implot" OFF) #OFF by default
option(FOX_IMGUI_IMPLOT_DEMO "Compile implot demo" OFF) #OFF by default

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE FOX_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE FOX_HEADERS "${PROJECT_SOURCE_DIR}/src/*.h")

add_executable(${CMAKE_PROJECT_NAME} ${FOX_SOURCES} ${FOX_HEADERS})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})

source_group(TREE "${PROJECT_SOURCE_DIR}/src" PREFIX "sources" FILES ${FOX_SOURCES} ${FOX_HEADERS})

set(FOX_IMGUI_DIR ${PROJECT_SOURCE_DIR}/lib/imgui)
set(FOX_IMGUI_IMPLOT_DIR ${PROJECT_SOURCE_DIR}/lib/implot)
set(FOX_GLFW_DIR ${PROJECT_SOURCE_DIR}/lib/glfw)

set(FOX_IMGUI_SOURCES
${FOX_IMGUI_DIR}/imgui.cpp
${FOX_IMGUI_DIR}/imgui_draw.cpp
${FOX_IMGUI_DIR}/imgui_tables.cpp
${FOX_IMGUI_DIR}/imgui_widgets.cpp
${FOX_IMGUI_DIR}/backends/imgui_impl_glfw.cpp
${FOX_IMGUI_DIR}/backends/imgui_impl_opengl3.cpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${FOX_IMGUI_DIR}")
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${FOX_IMGUI_DIR}/backends")



if(FOX_IMGUI_DEMO)
	set(FOX_IMGUI_SOURCES "${FOX_IMGUI_SOURCES};${FOX_IMGUI_DIR}/imgui_demo.cpp")
endif(FOX_IMGUI_DEMO)

if(FOX_IMGUI_IMPLOT)
    set(FOX_IMGUI_SOURCES "${FOX_IMGUI_SOURCES};${FOX_IMGUI_IMPLOT_DIR}/implot.cpp;${FOX_IMGUI_IMPLOT_DIR}/implot_items.cpp")
	target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${FOX_IMGUI_IMPLOT_DIR}")
    if(FOX_IMGUI_IMPLOT_DEMO)
        set(FOX_IMGUI_SOURCES "${FOX_IMGUI_SOURCES};${FOX_IMGUI_IMPLOT_DIR}/implot_demo.cpp")
    endif(FOX_IMGUI_IMPLOT_DEMO)
endif(FOX_IMGUI_IMPLOT)


# GLWF
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
set(GLFW_BUILD_EXAMPLES OFF)
add_subdirectory(${FOX_GLFW_DIR})




# opengl
find_package(OpenGL REQUIRED)
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  target_link_libraries(${CMAKE_PROJECT_NAME} opengl32.lib gdi32.lib shell32.lib)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  target_link_libraries(${CMAKE_PROJECT_NAME} GL)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
  SET(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
  target_link_libraries(${CMAKE_PROJECT_NAME} "-framework OpenGL")
  target_link_libraries(${CMAKE_PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${CMAKE_PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${CMAKE_PROJECT_NAME} "-framework CoreVideo")
endif()

add_library(imgui STATIC ${FOX_IMGUI_SOURCES})
target_include_directories(imgui PUBLIC "${FOX_IMGUI_DIR}")
target_include_directories(imgui PUBLIC "${FOX_IMGUI_DIR}/backends")
target_link_libraries(imgui glfw)

target_link_libraries(${CMAKE_PROJECT_NAME}  imgui)


