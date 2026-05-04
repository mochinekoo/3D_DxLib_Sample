#include "DxLib.h"
#include "framework.h"
#include <assert.h>
#include "Manager/SceneManager.h"
#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_win32.h"
#include "ImGUI/imgui_impl_dx11.h"

using namespace std;

HRESULT initDxLib();
HRESULT initImGUI();
void UpdateMainLoop();
void DrawMainLoop();
void shutdownApp();
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WinMain(_In_ HINSTANCE hInstance,
            _In_opt_ HINSTANCE hPrevInstance,
            _In_ LPSTR lpCmdLine,
            _In_ int nShowCmd) {
    static HRESULT result = {};
    
    result = initDxLib(); //DxLibの初期化
	assert(SUCCEEDED(result));
    result = SceneManager::InitManager(); //SceneManagerの初期化
	assert(SUCCEEDED(result));
	result = initImGUI(); //ImGUIの初期化
	assert(SUCCEEDED(result));

    while (ProcessMessage() == 0) { //
        ClearDrawScreen();

        UpdateMainLoop();
        DrawMainLoop();

        ScreenFlip();
        WaitTimer(1000 / GameScreen::FPS);
    }
    
    shutdownApp();
    return 0;
}

void UpdateMainLoop() {
    BaseScene* currentScene = SceneManager::GetCurrentScene();
    if (currentScene != nullptr) {
        currentScene->Update();
    }
    
}

void DrawMainLoop() {
	ImGui_ImplWin32_NewFrame();
	ImGui_ImplDX11_NewFrame();
    ImGui::NewFrame();

    BaseScene* currentScene = SceneManager::GetCurrentScene();
    if (currentScene != nullptr) {
        currentScene->Draw();
    }

    ImGui::Begin("MainWindow");
    ImGui::End();

    ImGui::EndFrame();
	ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    RefreshDxLibDirect3DSetting();
    if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }
}

HRESULT initDxLib() {
    SetMainWindowText(GameScreen::TITLE); //ウインドウのタイトル
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_16X16); //アンチエイリアシング＆エッジが使えるように
    ChangeWindowMode(true); //ウインドウモードで起動する
    SetGraphMode(GameScreen::WIDTH, GameScreen::HEIGHT, GameScreen::COLORBIT); //画面の設定
    SetWindowSizeChangeEnableFlag(FALSE); //ウインドウのサイズ変更
    SetAlwaysRunFlag(true); //ウインドウがアクティブじゃなくても実行
    SetUseZBuffer3D(true); //Zバッファを使用する
    SetWriteZBuffer3D(true); //Zバッファに書き込む
    SetUseDirect3DVersion(DX_DIRECT3D_11); //HLSLを使用するための、DirectX
    if (DxLib_Init() == -1) {
        return -1;
    }
    SetHookWinProc([](HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT {
        return ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);
    });

    SetBackgroundColor(GameScreen::BACKGROUND[0], GameScreen::BACKGROUND[1], GameScreen::BACKGROUND[2]);
    SetDrawScreen(DX_SCREEN_BACK);

    return S_OK;
}

HRESULT initImGUI() {
    ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();  
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsLight();
	ImGui_ImplWin32_Init(GetMainWindowHandle());
    ID3D11Device* device = (ID3D11Device*)GetUseDirect3D11Device();
    ID3D11DeviceContext* deviceContext = (ID3D11DeviceContext*)GetUseDirect3D11DeviceContext();
    ImGui_ImplDX11_Init(device, deviceContext);

    return S_OK;
}

void shutdownApp() {
	ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    SceneManager::ReleaseManager();
    DxLib_End();
}