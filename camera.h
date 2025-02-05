#pragma once

//ソースファイルの読み込み
#include <Novice.h>

//ヘッダーファイルの読み込み（アルファベット順）
#include"define.h"
#include"structuer.h"


class Camera {
private:

	struct Ortho {
		//初期の描画範囲
		float InitialRight;
		float InitialLeft;
		float InitialTop;
		float InitialBottom;

		//拡縮後の描画範囲
		float Right;
		float Left;
		float Top;
		float Bottom;

		Matrix3x3 orthoMatrix;

		//ズームイン・ズームアウト用の拡大率を格納する変数
		float Scale;
	};
	Ortho O;

	struct Viewport {
		float Width;
		float Height;
		float Left;
		float Top;

		Matrix3x3 viewportMatrix;
	};
	Viewport view;


	Matrix3x3 camera;
	Vector2 CameraPos;

public:



	//カメラ関連の初期化関数
	void CameraInitialize();

	//カメラの拡縮
	void CameraUpdate();

	//レンダリングパイプライン(返り値がvpvMatrix)
	Matrix3x3 MakeVPVMatrix(Matrix3x3 M, Vector2 origin);

	Matrix3x3 MakeOrthoMatrix();

	Matrix3x3 MakeViewportMatrix();


};

