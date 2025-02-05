#pragma once

/*======================================
				Vector
 ======================================*/

class Vector2 {
public:
	float x;
	float y;

	Vector2 NormalizeVector();
};

class IntVector2 {
public:
	int x;
	int y;

	IntVector2 NormalizeIntVector();
};

/*======================================
				Matrix
 ======================================*/
class Matrix3x3 {
public:
	float m[3][3];
};

/*======================================
				Color
 ======================================*/
class ColorStruct {
public:
	int Red;
	int Green;
	int Blue;
	int alpha;

	//上記四つをまとめたもの
	int color;

	void SetColor() {
		color = 0x01000000 * Red + 0x00010000 * Green + 0x00000100 * Blue + 0x00000001 * alpha;
	}
};
