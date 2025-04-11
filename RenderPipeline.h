#pragma once
#include"camera.h"

class RenderPipeline
{
public:
	Camera* activeCamera;
	float screenWidth, screenHeight;

public:
	RenderPipeline(){
		activeCamera = new Camera;
		screenWidth = 1280;
		screenHeight = 720.0f;
	}

	//カメラの設定
	void SetCamera(Camera& camera);
	//ビューポート変換
	Vector2 ApplyViewportTransform(Vector4 clipPos);
	//Gameobject描画
	void Render(GameObject& obj);
};