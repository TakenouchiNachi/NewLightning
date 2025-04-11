#pragma once

//ソースファイルの読み込み
#include <Novice.h>
#include <cmath>

//ヘッダーファイルの読み込み（アルファベット順）
#include"define.h"
#include"BaseClass.h"
#include"structuer.h"

class Camera : public Transform{
public:
	float zoom;					//2Dカメラのズーム
	int isOrthographic;			//2D or 3D(2Dならture 3Dならfalse)
	float aspectRatio;			//アスペクト比
	float nearPlane, farPlane;	//クリップ面

public:
	//コンストラクタ
	Camera()
		:zoom(1.0f), isOrthographic(true), aspectRatio(16.0f / 9.0f), nearPlane(0.1f), farPlane(100.0f){
	}

    // ビュー行列を取得（カメラの位置と回転を考慮）
	Matrix4x4 GetViewMatrix() const;
    // 射影行列（正射影 or 透視投影）
	Matrix4x4 GetProjectionMatrix(float screenWidth, float screenHeight) const;
};

