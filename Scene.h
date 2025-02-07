#pragma once
#include"InputManager.h"

class CommonData;
class Scene
{
protected:
	//コンストラクタ
	Scene(CommonData* const commonData) :
		commonData(commonData)
	{}
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

public:
	virtual Scene* Update() = 0;
	virtual void Draw() const = 0;

protected:
	template<typename T>
	Scene* makeScene() {};
};

class TitleScene : public Scene
{
public:
	TitleScene(CommonData* const commonData);
	virtual~TitleScene();
	Scene* Update() override;
	void Draw() const override;
};

class GameScene : public Scene
{
public:
	GameScene();
	Scene* Update() override;
	void Draw() const override;
};

class ResultScene : public Scene
{
public:
	ResultScene();
	Scene* Update() override;
	void Draw() const override;
};