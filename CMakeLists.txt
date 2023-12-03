cmake_minimum_required(VERSION 3.26)
project(Cashew CXX)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(external/glfw cashewlib-glfw-build-debug)
add_subdirectory(external/glm cashewlib-glm-build-debug)

set(IMGUI_PATH external/imgui)

file(GLOB IMGUI_GLOB
        ${IMGUI_PATH}/imgui.h
        ${IMGUI_PATH}/imgui.cpp
        ${IMGUI_PATH}/imconfig.h
        ${IMGUI_PATH}/imgui_demo.cpp
        ${IMGUI_PATH}/imgui_draw.cpp
        ${IMGUI_PATH}/imgui_internal.h
        ${IMGUI_PATH}/imstb_rectpack.h
        ${IMGUI_PATH}/imstb_textedit.h
        ${IMGUI_PATH}/imstb_truetype.h
        ${IMGUI_PATH}/imgui_tables.cpp
        ${IMGUI_PATH}/imgui_widgets.cpp

        ${IMGUI_PATH}/backends/imgui_impl_glfw.h
        ${IMGUI_PATH}/backends/imgui_impl_glfw.cpp
        ${IMGUI_PATH}/backends/imgui_impl_vulkan.h
        ${IMGUI_PATH}/backends/imgui_impl_vulkan.cpp
)

add_library("imgui" STATIC ${IMGUI_GLOB})
target_include_directories("imgui" PUBLIC ${IMGUI_PATH})
target_link_libraries("imgui" PRIVATE glfw)


find_package(Vulkan REQUIRED)

add_library(Cashew STATIC
  CashewLib/src/CashewLib/Layer.h
  CashewLib/src/CashewLib/Application.h
  CashewLib/src/CashewLib/Application.cpp
  CashewLib/src/CashewLib/EntryPoint.h
  CashewLib/src/CashewLib/Image.cpp
  CashewLib/src/CashewLib/Image.h
  CashewLib/src/CashewLib/Input/KeyCodes.h
  CashewLib/src/CashewLib/Input/Input.h
  CashewLib/src/CashewLib/Input/Input.cpp
)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(Cashew PRIVATE external/stb_image/)
include_directories(Cashew PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/CashewLib/src)

target_include_directories(Cashew PUBLIC ${IMGUI_PATH} ${Vulkan_INCLUDE_DIRS})
target_include_directories(Cashew PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(Cashew PUBLIC glfw imgui Vulkan::Vulkan glm)
set_target_properties(Cashew PROPERTIES LINKER_LANGUAGE CXX)
