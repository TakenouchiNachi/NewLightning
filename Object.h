#pragma once
#include"structuer.h"
#include"camera.h"

class Object
{
protected:
	//矩形の「scale」「rotate」「transrate」を制御する行列
	Matrix3x3 WorldMatrix;
	Matrix3x3 ScreenMatrix;

	/*  座標系  */
	//UIなどの貼り付けに使用
	Vector2 ScreenPos;

	//オブジェクトの処理に使用
	Vector2 WorldPos;

	/*  サイズ関連  */
	Vector2 Scale;
	float Width;
	float Height;

	/*  動き関連  */
	Vector2 Acceleration;
	Vector2 Velocity;
	Vector2 Vector;
	float Speed;

	//ベクトル取得に用いる
	float Degree;
	float Theta;

	/*  描画関連  */
	//画像の描画する座標
	Vector2 ImagePos;
	float ImageWIdth;

	float ImageHeight;

	//アニメーションに用いる
	float DrawWidth;
	float DrawHeight;

	//画像の回転に用いる
	float DrawDegree;
	float DrawTheta;

	//画像
	int Image;
	ColorStruct Color;


	//原点周りの四つ角
	Vector2 OriginLeftTop;
	Vector2 OriginLeftBottom;
	Vector2 OriginRightTop;
	Vector2 OriginRightBottom;

	//World座標で処理される四つ角
	Vector2 WorldLeftTop;
	Vector2 WorldLeftBottom;
	Vector2 WorldRightTop;
	Vector2 WorldRightBottom;

	//マップとの当たり判定
	IntVector2 MapCollisionLeftTop;
	IntVector2 MapCollisionLeftBottom;
	IntVector2 MapCollisionRightTop;
	IntVector2 MapCollisionRightBottom;

	//当たり判定用
	Vector2 CollisionLeftTop;
	Vector2 CollisionLeftBottom;
	Vector2 CollisionRightTop;
	Vector2 CollisionRightBottom;

	//描画用
	Vector2 DrawLeftTop;
	Vector2 DrawLeftBottom;
	Vector2 DrawRightTop;
	Vector2 DrawRightBottom;


public:

	//更新処理
	virtual void Update();

	//カメラを用いる描画
	void Draw(Matrix3x3 );

	//カメラを用いない描画（スクリーン座標での描画）
	void Draw();
};

