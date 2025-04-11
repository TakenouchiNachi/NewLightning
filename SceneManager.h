#pragma once
#include"Scene.h"
#include"CommonData.h"
#include"RenderPipeline.h"

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
	RenderPipeline* renderer;

public:

	Scene* Update() override;
	void Render(RenderPipeline& render) const;
};

