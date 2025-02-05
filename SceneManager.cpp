#include<Novice.h>

#include "SceneManager.h"
#include"CommonData.h"

class titleScene;

SceneManager::SceneManager():
	Scene(new CommonData()),
	mScene(makeScene<TitleScene>())
{}

SceneManager::~SceneManager() {
	if (mScene != nullptr) { delete mScene; };
}

Scene* SceneManager::Update() {
	// フレームの開始
	Novice::BeginFrame();
	//現在シーンの更新処理関数を呼び出す
	Scene* p = mScene->Update();
	//シーンが切り替わったら遷移先シーンのアドレス更新+前シーンのdelete
	if (p != mScene) {
		delete mScene;
		mScene = p;
	}
	//戻り値は特に関係ないのでnullptrを返す（継承の関係上、戻り値が必要）
	return nullptr;
}

void SceneManager::Draw() const{
	mScene->Draw();
	// フレームの終了
	Novice::EndFrame();
}