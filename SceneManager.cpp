#include<Novice.h>
#include "SceneManager.h"

class titleScene;
SceneManager::SceneManager() :
	Scene(new CommonData()),
	mScene(makeScene<TitleScene>()){
	renderer = new RenderPipeline();
}



SceneManager::~SceneManager() {
	if (mScene != nullptr) { delete mScene; };
}

Scene* SceneManager::Update() {
	// フレームの開始
	Novice::BeginFrame();
	//キー入力を受け取る
	memcpy(device.Key->preKeys, device.Key->keys, 256);
	Novice::GetHitKeyStateAll(device.Key->keys);
	//現在シーンの更新処理関数を呼び出す
	Scene* p = mScene->Update();
	//シーンが切り替わったら遷移先シーンのアドレス更新+前シーンのdelete
	if (p != mScene) {
		delete mScene;
		mScene = p;
	}
	return this;
}

void SceneManager::Render(RenderPipeline& render) const{
	mScene->Render(render);
	// フレームの終了
	Novice::EndFrame();
}