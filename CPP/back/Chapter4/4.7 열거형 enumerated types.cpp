#include <iostream>
#include <typeinfo>

enum Color { // user-defined data types
	COLOR_BLACK = -2,
	COLOR_RED = -2, // 같은 값으로 지정하는것은 권장 X
	BLUE,
	COLOR_GREEN,
};

enum Feeling {
	HAPPY,
	JOY,
	// BLUE, 컴파일 에러 
};

int main() {
	using namespace std;
	
	Color paint = COLOR_BLACK;
	// Color house(BLUE);
	Color appel{ COLOR_RED };

	if (COLOR_BLACK == COLOR_RED) {
		cout << "color_black = color_red" << endl;
	}

	Color my_color = static_cast<Color>(0); 
	// 얘는 가능
	
	return 0;
}