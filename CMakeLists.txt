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
add_executable (C-PlusPlus_DxLib_GameTemplate WIN32 "main.cpp" "framework.h")

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
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET C-PlusPlus_DxLib_GameTemplate PROPERTY CXX_STANDARD 20)
endif()

# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
