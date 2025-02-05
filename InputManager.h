#pragma once
class InputManager
{
	KEY* key;
};

class KEY {
public:
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};
