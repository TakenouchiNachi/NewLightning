#pragma once
#include <iostream>
#include <cmath>

/*======================================
				Vector
 ======================================*/

struct Vector2 {
public:
	float x;
	float y;

    //コンストラクタ
	Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}

	Vector2 NormalizeVector();
};

struct Vector3 {

    float x, y, z;

    // コンストラクタ
    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // ベクトル加算
    Vector3 operator+(const Vector3& other) const;
    // ベクトル同士の加算代入
    Vector3& operator+=(const Vector3& other);
    // ベクトル減算
    Vector3 operator-(const Vector3& other) const;
    // ベクトル同士の減算代入
    Vector3& operator-=(const Vector3& other);
    // スカラー乗算
    Vector3 operator*(float scalar) const;
    // ベクトルとスカラーの乗算代入
    Vector3& operator*=(float scalar);
    // スカラー除算
    Vector3 operator/(float scalar) const;
    // ベクトルとスカラーの除算代入
    Vector3& operator/=(float scalar);
    // 内積（Dot Product）
    float Dot(const Vector3& other) const;
    // 外積（Cross Product）
    Vector3 Cross(const Vector3& other) const;
    // ベクトルの長さ
    float Length() const;
    // 正規化（Normalize）
    Vector3 Normalize() const;
};

struct Vector4 {
    float x, y, z, w;

    //コンストラクタ
    Vector4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
    Vector4(const Vector3& v, float w_) : x(v.x), y(v.y), z(v.z), w(w_) {}
    };

/*======================================
				Matrix
 ======================================*/
struct  Matrix3x3 {
public:
	float m[3][3];
};

struct  Matrix4x4 {
public:
    float m[4][4];

    // コンストラクタ
    //Matrix4x4();

    //行列同士の乗算
    Matrix4x4 operator*(const Matrix4x4& other) const;
    //Matrix4x4とVector3の乗算
    Vector3 operator*(const Vector3& vec) const;
    // 3×3 の小行列を取得
    void GetMinorMatrix(int row, int col, float minor[3][3]) const;
    // 3×3 の行列式を求める
    float Determinant3x3(float mat[3][3]) const;
    // Cofactor（余因子）を求める
    float Cofactor(int row, int col) const;
    // 行列の行列式を求める（4×4 の行列式）
    float Determinant() const;
    // 逆行列を求める
    void Invert(Matrix4x4& out) const;

    // `Matrix4x4 * Vector4` のオーバーロード
    Vector4 operator*(const Vector4& v) const;

};

/*======================================
                Quaternion
 ======================================*/
struct Quaternion {
    float w, x, y, z;

    static Quaternion Identity() {
        Quaternion ret;

        ret.w = 1;
        ret.x = 0;
        ret.y = 0;
        ret.z = 0;
        
        return ret;
    }

    // クォータニオンの掛け算（回転の合成）
    Quaternion operator*(const Quaternion& q) const;
    // クォータニオンの正規化
    Quaternion Normalize();
    // クォータニオンの共役（逆回転用）
    Quaternion Conjugate() const;
    //回転行列の作成
    Matrix4x4 GetRotateMatrix() const;
};

/*======================================
				Color
 ======================================*/
class ColorStruct {
public:
    //三原色＋α
    Vector4 RGBA;
    //上記四つをまとめたもの
    int color;
public:
    //コンストラクタ
    ColorStruct(Vector4 rgba) : RGBA(rgba), color(0) {}
    void SetColor();
};
