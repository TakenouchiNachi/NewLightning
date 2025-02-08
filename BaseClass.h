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

	Transform(): pos(0, 0, 0), rotation(Quaternion::Identity()), scale(1, 1, 1) {}   //単位行列について調べる
};
//==============================================================================================
class Rigidbody {
public:
	Transform* transform;  //transform へのポインタ
	Vector3 velocity;
	Vector3 acceleration;
	float mass = 1.0f;
	float drag = 0.0f;

	Rigidbody(Transform* t) : transform(t){}

	void ApplyForce(const Vector3& force) {
		acceleration = force / mass;
	}

	void Update(float deltaTime) {
		velocity += acceleration * deltaTime;
		velocity *= (1.0f - drag * deltaTime);
		transform->pos += velocity * deltaTime;
		acceleration = Vector3(0, 0, 0); // 力をリセット
	}
};
//==============================================================================================
