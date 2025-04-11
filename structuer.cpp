#include <iostream>
#include <array>

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
Vector3& Vector3::operator-=(const Vector3 & other) {
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
Vector3& Vector3::operator/=(float scalar) {
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
                Vector4
 ======================================*/


/*======================================
				Matrix
 ======================================*/

//Matrix4x4::Matrix4x4() {
//    for (int y = 0; y < 4; y++) {
//        for (int x = 0; x < 4; x++) {
//            m[y][x] = 0;
//        }
//    }
//}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}

Vector3 Matrix4x4::operator*(const Vector3& vec) const {
    float x = m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z + m[0][3] * 1.0f;
    float y = m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z + m[1][3] * 1.0f;
    float z = m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z + m[2][3] * 1.0f;
    float w = m[3][0] * vec.x + m[3][1] * vec.y + m[3][2] * vec.z + m[3][3] * 1.0f;

    if (w != 0.0f) {
        x /= w;
        y /= w;
        z /= w;
    }

    return Vector3(x, y, z);
}

void Matrix4x4::GetMinorMatrix(int row, int col, float minor[3][3]) const {
    int minorRow = 0, minorCol = 0;
    for (int i = 0; i < 4; i++) {
        if (i == row) continue; // `row` 行を飛ばす
        minorCol = 0;
        for (int j = 0; j < 4; j++) {
            if (j == col) continue; // `col` 列を飛ばす
            minor[minorRow][minorCol] = m[i][j];
            minorCol++;
        }
        minorRow++;
    }
}

float Matrix4x4::Determinant3x3(float mat[3][3]) const {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
        - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
        + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
} 

// Cofactor（余因子）を求める
float Matrix4x4::Cofactor(int row, int col) const {
    float minor[3][3];
    GetMinorMatrix(row, col, minor);
    float detMinor = Determinant3x3(minor);
    return ((row + col) % 2 == 0 ? 1.0f : -1.0f) * detMinor; // 符号を適用
}

float Matrix4x4::Determinant() const {
    float det =
        m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
        m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
        m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
        m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
        m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
        m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
        m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
        m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
        m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
        m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
        m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
        m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];

    return det;
}

void Matrix4x4::Invert(Matrix4x4& out) const {
    float det = Determinant();
    float invDet = 1.0f / det;
    Matrix4x4 cofactorMatrix;

    // 余因子行列を計算
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cofactorMatrix.m[i][j] = Cofactor(i, j);
        }
    }

    // 余因子行列を転置（随伴行列 adj(A)）
    Matrix4x4 adjugateMatrix;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            adjugateMatrix.m[i][j] = cofactorMatrix.m[j][i]; // 転置
        }
    }

    // 逆行列 = 1/det(A) * adj(A)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out.m[i][j] = adjugateMatrix.m[i][j] * invDet;
        }
    }
}

// Matrix4x4 * Vector4 のオーバーロード
Vector4 Matrix4x4::operator*(const Vector4& v) const {
    return Vector4(
        m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w,
        m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w,
        m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w,
        m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w
    );
}
/*======================================
			  Quaternion
======================================*/
// クォータニオンの掛け算（回転の合成）
Quaternion Quaternion::operator*(const Quaternion& q) const {
    Quaternion ret;
    ret.w = w * q.w - x * q.x - y * q.y - z * q.z;
    ret.x = w * q.x + x * q.w + y * q.z - z * q.y;
    ret.y = w * q.y - x * q.z + y * q.w + z * q.x;
    ret.z = w * q.z + x * q.y - y * q.x + z * q.w;
    return ret;
}

// クォータニオンの正規化
Quaternion Quaternion::Normalize() {
    float mag = sqrt(w * w + x * x + y * y + z * z);
    Quaternion ret;
    ret.w = w / mag;
    ret.x = x / mag;
    ret.y = y / mag;
    ret.z = z / mag;

    return ret;
}

// クォータニオンの共役（逆回転用）
Quaternion Quaternion::Conjugate() const {
    Quaternion ret;
    ret.w = w;
    ret.x = -x;
    ret.y = -y;
    ret.z = -z;

    return ret;
}

Matrix4x4 Quaternion::GetRotateMatrix() const {

    return Matrix4x4({
            {1 - 2 * (y * y + z * z), 2 * (x * y - w * z), 2 * (x * z + w * y), 0},
            {2 * (x * y + w * z), 1 - 2 * (x * x + z * z), 2 * (y * z - w * x), 0},
            {2 * (x * z - w * y), 2 * (y * z + w * x), 1 - 2 * (x * x + y * y), 0},
            {0, 0, 0, 1}
    });
}
/*======================================
				Color
 ======================================*/

void ColorStruct::SetColor() {
	color = static_cast<int>(0x01000000 * RGBA.x + 0x00010000 * RGBA.y + 0x00000100 * RGBA.z + 0x00000001 * RGBA.w);
}
