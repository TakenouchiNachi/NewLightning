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
    Vector3& operator+=(const Vector3& other);
    // スカラー乗算
    Vector3 operator*(float scalar) const;
    // ベクトルとスカラーの乗算代入
    Vector3& operator*=(float scalar);
    // スカラー除算
    Vector3 operator/(float scalar) const;
    // ベクトルとスカラーの除算代入
    Vector3& operator*=(float scalar);
    // 内積（Dot Product）
    float Dot(const Vector3& other) const;
    // 外積（Cross Product）
    Vector3 Cross(const Vector3& other) const;
    // ベクトルの長さ
    float Length() const;
    // 正規化（Normalize）
    Vector3 Normalize() const;
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
};

/*======================================
                Quaternion
 ======================================*/
struct Quaternion {
    float w, x, y, z;

    Quaternion() : w(1), x(0), y(0), z(0) {}
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    static Quaternion Identity() {
        return Quaternion(1, 0, 0, 0);
    }

    // クォータニオンの掛け算（回転の合成）
    Quaternion operator*(const Quaternion& q) const {
        return Quaternion(
            w * q.w - x * q.x - y * q.y - z * q.z,
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y - x * q.z + y * q.w + z * q.x,
            w * q.z + x * q.y - y * q.x + z * q.w
        );
    }

    // クォータニオンの正規化
    Quaternion Normalize() {
        float mag = sqrt(w * w + x * x + y * y + z * z);
        return Quaternion(w / mag, x / mag, y / mag, z / mag);
    }

    // クォータニオンの共役（逆回転用）
    Quaternion Conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }

    // クォータニオンの表示
    void Print() const {
        std::cout << "Quaternion(" << w << ", " << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

/*======================================
				Color
 ======================================*/
class ColorStruct {
public:
	int Red;
	int Green;
	int Blue;
	int alpha;

	//上記四つをまとめたもの
	int color;

	void SetColor() {
		color = 0x01000000 * Red + 0x00010000 * Green + 0x00000100 * Blue + 0x00000001 * alpha;
	}
};
