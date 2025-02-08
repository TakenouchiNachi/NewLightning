#include "structuer.h"
#include"math.h"

/*======================================
				Vector2
 ======================================*/

Vector2 Vector2::NormalizeVector() {

	float length = sqrtf((x * x) + (y * y));

	Vector2 result;

	if (!length == 0) {
		result.x = x / length;
		result.y = y / length;
	}
	else {
		result.x = this->x;
		result.y = this->y;
	}
	return result;
}
/*======================================
				Vector3
 ======================================*/
 // ベクトル加算
Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}
// ベクトル同士の加算代入
Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x; y += other.y; z += other.z;
    return *this;
}

// ベクトル減算
Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}
// ベクトル同士の減算代入
Vector3& Vector3::operator+=(const Vector3 & other) {
    x -= other.x; y -= other.y; z -= other.z;
    return *this;
}

// スカラー乗算
Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}
// ベクトルとスカラーの乗算代入
Vector3& Vector3::operator*=(float scalar) {
    x *= scalar; y *= scalar; z *= scalar;
    return *this;
}

// スカラー除算
Vector3 Vector3::operator/(float scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}
// ベクトルとスカラーの除算代入
Vector3& Vector3::operator*=(float scalar) {
    x /= scalar; y /= scalar; z /= scalar;
    return *this;
}

// 内積（Dot Product）
float Vector3::Dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// 外積（Cross Product）
Vector3 Vector3::Cross(const Vector3& other) const {
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// ベクトルの長さ
float Vector3::Length() const {
    return std::sqrt(x * x + y * y + z * z);
}

// 正規化（Normalize）
Vector3 Vector3::Normalize() const {
    float length = Length();
    return (length > 0) ? (*this) * (1.0f / length) : Vector3(0, 0, 0);
}


/*======================================
				Matrix
 ======================================*/
class Matrix3x3 {
	float m[3][3];
};

/*======================================
				Color
 ======================================*/
class ColorStruct {
	int Red;
	int Green;
	int Blue;
	int alpha;

	//上記四つをまとめるもの
	int color;

	void SetColor() {
		color = 0x01000000 * Red + 0x00010000 * Green + 0x00000100 * Blue + 0x00000001 * alpha;
	}
};
