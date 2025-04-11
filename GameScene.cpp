#include<Novice.h>
#include"Scene.h"

template<>
Scene* Scene::makeScene<GameScene>() {
	return new GameScene(commonData);
}

GameScene::GameScene(CommonData* const commonData) : Scene(commonData) {
	player = new Player;
}

GameScene::~GameScene() {

}

Scene* GameScene::Update() {	

	return this; 
}

void GameScene::Render(RenderPipeline& renderer) const {
	renderer.Render(*player);
	renderer;
}