#pragma once

//ソースファイルの読み込み
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string> 
//ヘッダーファイルの読み込み
#include"structuer.h"

//==============================================================================================
class Transform {
public:
	//行列
	Matrix4x4 mat;
	//座標
	Vector3 pos;
	//大きさ
	Vector3 scale;
	//回転（向き）
	Quaternion rotation;

	Transform()
		: pos(0, 0, 0), rotation(Quaternion::Identity()), scale(1, 1, 1) {}
};
//==============================================================================================
class Rigidbody {
	Transform* transform;  //transform へのポインタ
};