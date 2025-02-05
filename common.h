#pragma once

//ソースファイルの読み込み
#include<math.h>

//ヘッダーファイルの読み込み
#include"structuer.h"

//オブジェクトの四つ角を計算する関数
void SetFourVertexes(RectangleObject* obj);

//アフィン変換行列の生成
//（rotate:theta    translate: velocity）だと考えている
Matrix3x3 MakeAffineMatrix(Vector2 scale, float rotate, Vector2 translate);

//アフィン行列の計算をVector2型に変換
Vector2 Transform(Vector2 vector, Matrix3x3 matrix);

//行列の計算
Matrix3x3 Inverse(Matrix3x3 M);

Matrix3x3 Multiply(Matrix3x3 a, Matrix3x3 b);

//ベクトル正規化関数
Vector2 NormalizeVector(Vector2 vec);

IntVector2 NormalizeIntVector(IntVector2 vec);

//線形補完関数
Vector2 Lerp(float t, Vector2 p1, Vector2 p2);

//矩形の当たり判定をとる関数(引数に対象の２つのオブジェクトを指定,trueなら1を返す falseなら0を返す)
int RectangleObjectCollision(RectangleObject* obj1, RectangleObject* obj2);

//2物体の距離を測る関数
float Distance(Vector2 obj1, Vector2 obj2);