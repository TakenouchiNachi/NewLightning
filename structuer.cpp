#include "structuer.h"
#include"math.h"

/*======================================
				Vector
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

IntVector2 IntVector2::NormalizeIntVector() {
	float length = sqrtf((x * x) + (y * y));

	IntVector2 result;

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
				Matrix
 ======================================*/
class Matrix3x3 {
	float m[3][3];
};

/*======================================
				Color
 ======================================*/
class ColorStruct {
	int Red;
	int Green;
	int Blue;
	int alpha;

	//上記四つをまとめるもの
	int color;

	void SetColor() {
		color = 0x01000000 * Red + 0x00010000 * Green + 0x00000100 * Blue + 0x00000001 * alpha;
	}
};
