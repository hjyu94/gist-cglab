#include <iostream>
#include <bitset>

using namespace std;

int main() {
	// 16진수 색 표현에서
	// r,g,b 값 추출
	
	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << bitset<32>(red_mask) << endl;
	cout << bitset<32>(green_mask) << endl;
	cout << bitset<32>(blue_mask) << endl;
	cout << endl;

	unsigned int pixel_color = 0xDAA520;	
	cout << "pixel color: " << bitset<32>(pixel_color) << endl;
	cout << endl;

	unsigned char blue; // 8 bit
	// unsigned int green; // 32 bit
	unsigned char green;
	unsigned char red;

	blue = pixel_color & blue_mask;
	green = (pixel_color & green_mask) >> 8;
	red = (pixel_color & red_mask) >> 16;

	cout << "blue: " << bitset<8>(blue) << " : " << int(blue) << endl;
	cout << "green: " << bitset<8>(green) << " : " << int(green) << endl;
	cout << "red: " << bitset<8>(red) << " : " << int(red) << endl;


	return 0;
}