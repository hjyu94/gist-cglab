#include <iostream>
#include <typeinfo>

enum Color { // user-defined data types
	COLOR_BLACK = -2,
	COLOR_RED = -2, // ���� ������ �����ϴ°��� ���� X
	BLUE,
	COLOR_GREEN,
};

enum Feeling {
	HAPPY,
	JOY,
	// BLUE, ������ ���� 
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
	// ��� ����
	
	return 0;
}