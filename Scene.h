#pragma once
#include"InputManager.h"
#include"structuer.h"
#include"RenderPipeline.h"
#include"Player.h"


class CommonData;
class Scene{
protected:
	//コンストラクタ
	Scene(CommonData* const commonData) :
		commonData(commonData){
		camera = new Camera();
	}
public:
	//コピー禁止
	Scene(const Scene&) = delete;
	//コピー禁止
	Scene& operator=(const Scene&) = delete;

	//仮想関数化したデストラクタ
	virtual ~Scene() = default;

protected:
	//共有データ
	CommonData* const commonData;
	//Camera(各シーンに一つ持たせる)
	Camera* camera;
public:
	virtual Scene* Update() = 0;
	virtual void Render(RenderPipeline& renderer) const = 0;

protected:
	template<typename T>
	Scene* makeScene();

public:
	//入力関係
	InputManager device;
};

class TitleScene : public Scene
{
public:
	TitleScene(CommonData* const commonData);
	virtual~TitleScene();
	Scene* Update() override;
	void Render(RenderPipeline& renderer) const override;
};

class GameScene : public Scene
{
public:
	GameScene(CommonData* const commonData);
	virtual~GameScene();
	Scene* Update() override;
	void Render(RenderPipeline& renderer) const override;

private:
	Player* player;
};

class ResultScene : public Scene
{
public:
	ResultScene(CommonData* const commonData);
	virtual~ResultScene();
	Scene* Update() override;
	void Render(RenderPipeline& renderer) const override;
};