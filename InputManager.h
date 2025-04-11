#pragma once

class KEY {
public:
	// キー入力結果を受け取る箱
	static char keys[256];
	static char preKeys[256];

public:
};

class InputManager {
public:
	InputManager();
public:
	KEY* Key;
};
