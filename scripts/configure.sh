#!/bin/bash
mkdir ../build
cd ../build
cmake -D GLFW_BUILD_WAYLAND=OFF ..
