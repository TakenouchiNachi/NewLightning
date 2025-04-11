#include "Player.h"

Player::Player(){
	//画像を読み込む
}

Player::~Player()
{
}

void Player::RenderInitialize(int texID){
	renderComponent->textureID = texID;
}

void Player::Update(){

}

void Player::Draw(Vector2 pos){
	Draw_2D(pos);
}
