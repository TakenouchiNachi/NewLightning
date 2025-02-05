#include <Novice.h>
#include"SceneManager.h"

const char kWindowTitle[] = "LC1A_15_タケノウチ_ナチ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	//インスタンス化
	SceneManager* scenemanager = new SceneManager;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		//更新処理
		scenemanager->Update();

		//描画処理
		scenemanager->Draw();
	}
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
