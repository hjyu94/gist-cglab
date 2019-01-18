// 컴파일러의 도움을 받아서 디버깅 시간을 줄이자

#include <iostream>
#include <cassert> // assert.h
#include <array>

using namespace std;

void printValue(const std::array<int, 5> &my_array, const int& ix) {
	// 파라매터에 레퍼런스 변수 사용 -> 주소를 복사해옴.
	// 포인터 변수 넘겨줄때보다 좀 더 편하게 사용 가능
	// const를 붙인 이유 -> 함수 내부에서 파라매터 값이 바뀌지 않도록 하려고
	
	// 두 이유 중 어느 이유 때문인지 알려면 더 나눠서 써주면 된다.
	// assert(ix >= 0 && ix <= my_array.size() - 1);
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1);

	std::cout << my_array[ix] << std::endl;
}

int main() {
	// 디버그 모드에서 소프트웨어를 테스트 할 때만 작동

	// 속성 - Preprocessor - 
	//    preprocessor definitions에 WIN32;NDEBUG 값이 있으면 작동 안함  

	// release 모드에선 가급적 프로그램이 빠르게 돌아야 하기 때문에
	// assert가 작동하지 않는 것

	// assert(false);

	/**************************************************/

	int number = 5;
	
	// ...
	// 이 과정에서 number가 값이 바뀔 수도 있는데 ...

	assert(number == 5);
	// number should be 5
	// 현재 줄에서 반드시 5여야 한다면
	// 개발자에게 주석을 읽으라고 하는 것보단
	// 컴파일러가 에러를 내주는게 도움이 된다.

	/**************************************************/

	std::array<int, 5> my_array{ 1,2,3,4,5 };
	
	printValue(my_array, 100);
	// Assertion failed: ix >= 0 && ix <= my_array.size() - 1, file c:\users\cglab5\desktop\hjeong\c++\c++\chapter 7\7.14 단언 하기 assert.cpp, line 14
	
	return 0;
}