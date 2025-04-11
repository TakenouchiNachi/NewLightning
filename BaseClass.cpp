#include "BaseClass.h"
#include<Novice.h>
//==============================================================================================
Matrix4x4 Transform::GetAffineMatrix() const {
	Matrix4x4 rotMat = rotation.GetRotateMatrix();
	Matrix4x4 affine = {};

	//スケールの適用
	for (int i = 0; i < 3; i++) {
		affine.m[i][0] = rotMat.m[i][0] * scale.x;
		affine.m[i][1] = rotMat.m[i][1] * scale.y;
		affine.m[i][2] = rotMat.m[i][2] * scale.z;
	}
	//平行移動の適用
	affine.m[0][3] = pos.x;
	affine.m[1][3] = pos.y;
	affine.m[2][3] = pos.z;

	return affine;
}
//==============================================================================================
GameObject::GameObject() {
	transform = new Transform();
	rigidbody = new Rigidbody();
	renderComponent = new RenderComponent(0, Vector3(0, 0, 0));
	colider = new Colider();
}

void GameObject::Draw_2D(Vector2 pos) {
	RectShape tmpRect;
	tmpRect.LeftTop.x = pos.x - renderComponent->size.x;
	tmpRect.LeftTop.y = pos.y - renderComponent->size.y;
	tmpRect.LeftBottom.x = pos.x - renderComponent->size.x;
	tmpRect.LeftBottom.y = pos.y + renderComponent->size.x;
	tmpRect.RightTop.x = pos.x + renderComponent->size.x;
	tmpRect.RightTop.y = pos.y - renderComponent->size.y;
	tmpRect.RightBottom.x = pos.x + renderComponent->size.x;
	tmpRect.RightBottom.y = pos.y + renderComponent->size.x;

	//色の確定
	renderComponent->Color.SetColor();

	Novice::DrawQuad(
		static_cast<int>(tmpRect.LeftTop.x),
		static_cast<int>(tmpRect.LeftTop.y),
		static_cast<int>(tmpRect.RightTop.x),
		static_cast<int>(tmpRect.RightTop.y),
		static_cast<int>(tmpRect.LeftBottom.x),
		static_cast<int>(tmpRect.LeftBottom.y),
		static_cast<int>(tmpRect.RightBottom.x),
		static_cast<int>(tmpRect.RightBottom.y),
		static_cast<int>(renderComponent->ImagePos.x),
		static_cast<int>(renderComponent->ImagePos.y),
		static_cast<int>(renderComponent->size.x),
		static_cast<int>(renderComponent->size.y),
		renderComponent->textureID,
		renderComponent->Color.color
	);
}
