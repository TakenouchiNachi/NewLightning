#include"Scene.h"
template<>
Scene* Scene::makeScene<ResultScene>() {
	return new ResultScene(commonData);
}

ResultScene::ResultScene(CommonData* const commonData) : Scene(commonData) {

}

ResultScene::~ResultScene() {

}

Scene* ResultScene::Update() {
	return this;
}

void ResultScene::Render(RenderPipeline& renderer) const {
	renderer;
}