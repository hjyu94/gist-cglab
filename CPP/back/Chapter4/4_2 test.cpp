#include <iostream>
#include "4_2 MyConstants.h"

// extern int a ;
extern int extern_a = 12345;

void doSomething_in_other_cpp() {
	using namespace std;

	cout << "In test.cpp : " << Constants::pi << ", " << &Constants::pi << endl;
	cout << "세상에 주소가 다르게 찍힘, 상수가 엄청나게 많을 때는 메모리 낭비가 된다" << endl;
	cout << "해결법-> 헤더에는 정의만 남기고 cpp파일을 따로 만든 후 extern으로 선언한다" << endl;
}