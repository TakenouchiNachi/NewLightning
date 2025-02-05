#pragma once
#include"Scene.h"

class SceneManager final : public Scene
{
public:
	//コンストラクタとデストラクタ
	SceneManager();
	~SceneManager();

	//コピー禁止
	SceneManager(const SceneManager&) = delete;
	//コピー禁止
	SceneManager& operator=(const SceneManager&) = delete;

private:
	Scene *mScene;

public:

	Scene* Update() override;

	void Draw() const override;
};

