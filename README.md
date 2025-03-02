## Getting Started
### Clone
```sh
git clone --depth 1 https://github.com/WestFoxy/FoxUIBase
cd ./FoxUIBase
git submodule init
git submodule update --depth 1 --recursive
```
### Run
Download [CMake](https://cmake.org)

```sh
cd ./scripts
./configure.bat
```

Now in root there is **build** folder with sln project.

### Configure build
In **CMakeLists.txt**:
```sh
option(FOX_IMGUI_DEMO "Compile ImGui demo" OFF)
option(FOX_IMGUI_IMPLOT "Compile implot" OFF)
option(FOX_IMGUI_IMPLOT_DEMO "Compile implot demo" OFF)
```

### WSL
Build should be without wayland
```sh
cmake -D GLFW_BUILD_WAYLAND=OFF ..
```
X11 + OpenGL
```sh
sudo apt install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
```
```sh
sudo apt install libgl1-mesa-dev
```
