
//ソースファイルの読み込み
#include <Novice.h>

//ヘッダーファイルの読み込み（アルファベット順）
#include"common.h"
#include"camera.h"
#include"structuer.h"
#include"Object.h"

//カメラ関連の初期化関数
void Camera::CameraInitialize() {

	CameraPos = { -640,-360 };

	camera = {
		1,0,0,
		0,1,0,
		CameraPos.x,CameraPos.y,1
	};

	O.InitialLeft = -640.0f;
	O.InitialTop = 360.0f;
	O.InitialRight = 640.0f;
	O.InitialBottom = -360.0f;

	O.Scale = 1.0f;



	view.Left = 0.0f;
	view.Top = 0.0f;
	view.Width = 1280.0f;
	view.Height = 720.0f;
}


//カメラの拡縮
void Camera::CameraUpdate() {

	camera = {
		1,0,0,
		0,1,0,
		CameraPos.x,CameraPos.y,1
	};

	O.Left = O.InitialLeft * O.Scale;
	O.Top = O.InitialTop * O.Scale;
	O.Right = O.InitialRight * O.Scale;
	O.Bottom = O.InitialBottom * O.Scale;
}


Matrix3x3 Camera::GetVPVMatrix() {

	Matrix3x3 viewMatrix = Inverse(camera);
	O.orthoMatrix = GetOrthoMatrix();
	view.viewportMatrix = GetViewportMatrix();

	Matrix3x3 wvpVpMatrix = Multiply(M, camera);
	wvpVpMatrix = Multiply(wvpVpMatrix, O.orthoMatrix);
	wvpVpMatrix = Multiply(wvpVpMatrix, view.viewportMatrix);

	//描画用の四つ角
	return  wvpVpMatrix;
}

Matrix3x3 Camera::GetOrthoMatrix() {
	return{
		2.0f / (O.Right - O.Left),  0,  0,
		0,  2.0f / (O.Top - O.Bottom),  0,
		(O.Left + O.Right) / (O.Left - O.Right),  (O.Top + O.Bottom) / (O.Bottom - O.Top),  1
	};
}

Matrix3x3 Camera::GetViewportMatrix() {
	return{
	   view.Width / 2,  0,  0,
	   0,  -(view.Height / 2),  0,
	   view.Left + (view.Width / 2),  view.Top + (view.Height / 2),  1
	};
}
