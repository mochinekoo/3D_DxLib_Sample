# CMakeList.txt : C-PlusPlus_DxLib_GameTemplate の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.10)

# サポートされている場合は、MSVC コンパイラのホット リロードを有効にします。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("C-PlusPlus_DxLib_GameTemplate")

# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable (C-PlusPlus_DxLib_GameTemplate WIN32 
    "main.cpp" "framework.h" 
    "Manager/SceneManager.h" "Manager/SceneManager.cpp"  
    "Scene/BaseScene.h" "Scene/RootScene.h" "Scene/RootScene.cpp" 
    "ImGUI/imgui_impl_dx10.cpp" "ImGUI/imgui_impl_dx10.h" "ImGUI/imgui_impl_dx12.cpp" "ImGUI/imgui_impl_dx12.h" "ImGUI/imgui_impl_dx9.cpp" "ImGUI/imgui_impl_dx9.h" "ImGUI/imgui_impl_dx11.h" "ImGUI/imgui_impl_dx11.cpp" "ImGUI/imgui_impl_win32.cpp" "ImGUI/imgui_impl_win32.h"
    "ImGUI/imconfig.h" "ImGUI/imgui.h" "ImGUI/imgui.cpp" "ImGUI/imgui_draw.cpp" "ImGUI/imgui_widgets.cpp" "ImGUI/imgui_tables.cpp" "ImGUI/imstb_rectpack.h" "ImGUI/imstb_textedit.h" "ImGUI/imstb_truetype.h" "ImGUI/imgui_demo.cpp"
    "Library/Vector.hpp" "Library/Location.hpp" "Library/Matrix.hpp" )

# ライブラリ
target_include_directories(C-PlusPlus_DxLib_GameTemplate PUBLIC "C:/ProgramData/DxLib_VC/プロジェクトに追加すべきファイル_VC用/")
target_link_directories(C-PlusPlus_DxLib_GameTemplate PUBLIC "C:/ProgramData/DxLib_VC/プロジェクトに追加すべきファイル_VC用/")
link_directories("C:/ProgramData/DxLib_VC/プロジェクトに追加すべきファイル_VC用/")
target_link_libraries(C-PlusPlus_DxLib_GameTemplate PUBLIC
    DxLib
    winmm
    gdi32
    dinput8
    dxguid
    dxgi
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET C-PlusPlus_DxLib_GameTemplate PROPERTY CXX_STANDARD 20)
endif()

# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
