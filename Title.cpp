#include"Scene.h"

template<>
Scene* Scene::makeScene<TitleScene>() {
	return new TitleScene(commonData);
}

TitleScene::TitleScene(CommonData* const commonData) : Scene(commonData) {
	
}

TitleScene::~TitleScene() {

}

Scene* TitleScene::Update() {
	if (device.Key->keys[DIK_SPACE] && !device.Key->preKeys[DIK_SPACE]) {
		return makeScene<GameScene>();
	}
	return this;
}

void TitleScene::Render(RenderPipeline& renderer) const {
	renderer;
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x008888ff, kFillModeSolid);
}