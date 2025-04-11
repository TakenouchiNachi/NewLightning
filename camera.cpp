//ソースファイルの読み込み
#include <Novice.h>
#include <cmath>

//ヘッダーファイルの読み込み（アルファベット順）
#include"camera.h"

Matrix4x4 Camera::GetViewMatrix() const {
    Matrix4x4 rotationMatrix = rotation.GetRotateMatrix(); // 🔹 `Quaternion` を行列に変換
    Matrix4x4 translationMatrix;
    Matrix4x4 ret;

    translationMatrix.m[0][3] = -pos.x;
    translationMatrix.m[1][3] = -pos.y;
    translationMatrix.m[2][3] = -pos.z;

    ret = rotationMatrix * translationMatrix;
    ret.Invert(ret);

    return ret;
}

Matrix4x4 Camera::GetProjectionMatrix(float screenWidth, float screenHeight) const {
    Matrix4x4 proj;
    if (isOrthographic) {
        float left = -screenWidth / 2.0f, right = screenWidth / 2.0f;
        float bottom = -screenHeight / 2.0f, top = screenHeight / 2.0f;

        proj.m[0][0] = 2.0f / (right - left);
        proj.m[1][1] = 2.0f / (top - bottom);
        proj.m[2][2] = -2.0f / (farPlane - nearPlane);
        proj.m[3][3] = 1.0f;
    }
    else {
        float fov = 90.0f * (3.1415f / 180.0f); // 90度をラジアンに変換
        float tanHalfFov = std::tan(fov / 2.0f);
        float range = nearPlane - farPlane;

        proj.m[0][0] = 1.0f / (aspectRatio * tanHalfFov);
        proj.m[1][1] = 1.0f / tanHalfFov;
        proj.m[2][2] = (-nearPlane - farPlane) / range;
        proj.m[2][3] = 2.0f * farPlane * nearPlane / range;
        proj.m[3][2] = 1.0f;
        proj.m[3][3] = 0.0f;
    }
    return proj;
}