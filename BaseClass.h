#pragma once

//ソースファイルの読み込み
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string> 

//ヘッダーファイルの読み込み
#include"structuer.h"
#include"ResourceManager.h"

//==============================================================================================
class Transform {
public:
	Vector3 pos;
	Vector3 scale;
	Quaternion rotation;

	//オイラー角からクォータニオンを生成する関数
	void SetRotationEuler(const Vector3& euler);

	Transform(): pos(0, 0, 0), rotation(Quaternion::Identity()), scale(1, 1, 1) {} 
	Matrix4x4 GetAffineMatrix() const;
};
//==============================================================================================
class Rigidbody {
protected:
	Vector3 velocity;
	Vector3 acceleration;
	float mass = 1.0f;
	float drag = 0.0f;

	void ApplyForce(const Vector3& force) {
		acceleration = force / mass;
	}
};
//==============================================================================================
class RectShape {
public:
	Vector3 LeftTop;
	Vector3 LeftBottom;
	Vector3 RightTop;
	Vector3 RightBottom;

public:
	RectShape():LeftTop(0,0,0), LeftBottom(0, 0, 0), RightTop(0, 0, 0), RightBottom(0, 0, 0){}
};
//==============================================================================================
class RenderComponent {
public:
	int textureID;		 //画像の情報
	Vector3 size;		 //画像のサイズ
	Vector2 ImagePos;	 //画像上の座標
	ColorStruct Color;	 //画像の色

public:
	RenderComponent(int texID, Vector3 size_)
		: textureID(texID), size(size_),ImagePos(0,0), Color(Vector4(1, 1, 1, 1)) // Colorの初期化を追加
	{
	}
};
//==============================================================================================
class Colider {
protected:
	RectShape Rect;  //判定用の四つ角
	Vector3 size;	 //判定のサイズ（特になければ画像のサイズと同じように初期化）
public:
	Colider():Rect(RectShape::RectShape()){}
};
//==============================================================================================
class GameObject {
protected:
	Transform* transform;  
	Rigidbody* rigidbody;  //UI・HUDなど必要ないものはnullptrで初期化してあげる
	RenderComponent* renderComponent;
	Colider* colider; 

public:
	GameObject();
	virtual void RenderInitialize(int Ini_ID) = 0;
	virtual void Update() = 0;
	virtual void Draw(Vector2 pos) = 0;

	//2D用の描画
	void Draw_2D(Vector2 pos);

	//Getter
	Vector3 GetPos() { return transform->pos; };
	float GetPosX() { return transform->pos.x; };
	float GetPosY() { return transform->pos.y; };
	float GetPosZ() { return transform->pos.z; };
	Matrix4x4 GetWorldMatrix() { return transform->GetAffineMatrix(); };
	//Setter
};
//==============================================================================================