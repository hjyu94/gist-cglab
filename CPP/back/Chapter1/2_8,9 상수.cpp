#include <iostream>
#include "2_8_9 MY CONTANTS.h"

using namespace std;


// 이렇게 안 쓰는게 좋다.
// 디버깅이 힘들고, 적용범위가 너무 넓다.
#define CONST_COST = 30 ; 

void printNumber(const int my_number) {
	my_number = 10;
	// 파라매터로 넘겨준 변수 값을 바꿔서 사용하는건
	// 옳지 못함

}

int main() {
	printNumber(3);

	const int my_const(123); // compile time constant
	constexpr int my_const2(123); // compile time constant
	
	double radius;
	cin >> radius;
	double circumference = 2.0 * radius * constants::pi;

	int number;
	cin >> number;

	const int special_number(number); // run time constant

	number = 123; // 가능
	special_number = 123; // 불가능
}

