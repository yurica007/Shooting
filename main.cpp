#include "DxLib.h"
#include "GameScene.h"
#include "GameData.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//------------------------------------------------------
	// ウインドウ設定とDXライブラリの初期化
	//------------------------------------------------------
	// Windowsモードにする
	ChangeWindowMode(TRUE);
	// 画面サイズの設定
	SetGraphMode(Data::kDisplayWidth, Data::kDisplayHeight, Data::kColorData);

	// DXライブラリ初期化
	if (DxLib_Init() == -1)
	{
		//初期化に失敗
		return -1;
	}
	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	GameScene game;

	//------------------------------------------------------
	// ゲーム部分
	//------------------------------------------------------
	// メインループ処理
	while (ProcessMessage() == 0)
	{
		//裏画面消す
		ClearDrawScreen();

		game.Update();
		game.Draw();

		//裏画面を表画面を入れ替える
		ScreenFlip();

		//ESCAPEを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//------------------------------------------------------
	// DXライブラリ終了とプログラム終了
	//------------------------------------------------------
	DxLib_End();
	return 0;
}