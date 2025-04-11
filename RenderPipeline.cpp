#include "RenderPipeline.h"

void RenderPipeline::SetCamera(Camera& camera) {
    activeCamera = &camera;
}


Vector2 RenderPipeline::ApplyViewportTransform(Vector4 clipPos) {
    float x = (clipPos.x / clipPos.w + 1.0f) * 0.5f * screenWidth;
    float y = (1.0f - clipPos.y / clipPos.w) * 0.5f * screenHeight;
    return Vector2(x, y);
}

void RenderPipeline::Render(GameObject& obj) {
    // ワールド変換
    Matrix4x4 modelMatrix = obj.GetWorldMatrix();
    // カメラ座標変換
    Matrix4x4 viewMatrix = activeCamera->GetViewMatrix();
    // 透視投影
    Matrix4x4 projectionMatrix = activeCamera->GetProjectionMatrix(screenWidth, screenHeight);
    // クリップ座標の計算
    Vector4 worldPos(obj.GetPosX(),obj.GetPosY() ,obj.GetPosZ() ,1.0f );
    Vector4 clipPos = projectionMatrix * (viewMatrix * (modelMatrix * worldPos));
    // ビューポート変換
    Vector2 screenPos = ApplyViewportTransform(clipPos);
    // Draw関数にScreenPosを渡す
    obj.Draw(screenPos);
}