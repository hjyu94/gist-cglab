// #pragma once // 헤더 가드

// 1_11 에서는

// 함수의 선언은 헤더 파일에
// 함수의 정의는 cpp 파일을 따로 만들었는데

// 그렇게 하는게 좋긴 하지만
// 귀찮아서 헤더에 선언과 정의를 같이 초기화 하는 경우가 많다.

// MY_ADD가 정의되어있지 않다면
#ifndef MY_ADD 
// MY_ADD를 정의하라.
#define MY_ADD

// #ifndef, #define의 기능을 하는 명령문이
// #pragma once이다.

int add(int a, int b) {
	return a + b;
}

#endif