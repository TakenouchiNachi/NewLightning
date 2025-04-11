#include "InputManager.h"
#include<memory>
InputManager::InputManager() {
	//キー入力の初期化
	Key = new KEY();
}

//キーの初期化
char KEY::keys[256] = { 0 };
char KEY::preKeys[256] = { 0 };
