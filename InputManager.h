#pragma once
class InputManager{
public:
	InputManager();
public:
	KEY* Key;
};

class KEY {
public:
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};