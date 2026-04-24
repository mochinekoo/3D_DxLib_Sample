// C-PlusPlus_DxLib_GameTemplate.h : 標準のシステム インクルード ファイル用のインクルード ファイル、
// または、プロジェクト専用のインクルード ファイル。

#pragma once

#include <iostream>

// TODO: プログラムに必要な追加ヘッダーをここで参照します。

namespace GameScreen {
	inline const char* TITLE = "Game"; //ウインドウのタイトル
	inline const int WIDTH = 1280; //画面の幅
	inline const int HEIGHT = 720; //画面の高さ
	inline const int COLORBIT = 32; //カラービット
	inline const int BACKGROUND[3] = { 0, 0, 0 }; //画面の背景
	inline const int FPS = 60; //画面のフレームレート
}