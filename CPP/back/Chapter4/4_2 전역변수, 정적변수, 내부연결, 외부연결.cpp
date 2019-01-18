/*
	int g_x; // external linkage 초기화가 안된 전역변수
	static int g_x; // internal linkage 다른 cpp파일에서 접근할 수 없다 초기화되지 않은 정적변수이다.
	const int g_x ; // const를 값을 써주지 않으면 안된다.

	extern int g_z;
	extern const int g_x; 
	// 다른 곳 어디서는 이 값을 무조건 초기화 해줬어야 한다.

	int g_y(1);
	static int g_y(1); // 다른 곳에서 사용 불가능
	const int g_y(1); // 같은 파일 안에서만 사용

	extern int g_w(1); // 다른 곳에서는 초기화 해주면 안된다.
	extern const int g_w(1); // 다른 cpp파일에서 사용 가능

	뭔소리야...?
*/

#include <iostream>
#include "4_2 MyConstants.h"

using namespace std;

// forward declaration

// 다른 cpp 파일 어딘가에 이 함수의 정의가 존재하니까
// 링킹할 때 가져다 붙이세요 라는 의미
// #include "4_2 test.cpp" 처럼 슬 수도 있지만 이는 비추

// 이 때 extern은 생략 가능하다.
extern void doSomething_in_other_cpp();

// 컴파일할 땐 아 그래 ok 어딘가 있겠지 했는데
// 링킹하려고 보니까 obj 파일을 전부 뒤져도
// 정의된 곳이 없다. 메모리가 없다.
// 여기서 문제는 초기화가 안돼있었다는 것 -> 초기화 마저 해준다.
extern int extern_a;

int value = 123;

void doSomething() {
	int a = 1;
	++a;
	cout << a << endl;
}

void doSomething_static() {
	/*
		이렇게 쓰면 무시됨
		static 변수는 선언과 동시에 초기화 되어야 한다

		static int a;
		a = 1;
	*/

	static int a = 1; 
	// static은 한번 초기화되면 두번째 초기화 명령문은 무시하고 넘어간다.
	// 마치 전역변수에 int a = 1;인 꼴과 같다.
	++a;
	cout << a << endl;
}
// static duration var.
// static: 변수 a가 메모리로부터 받은 메모리
// 즉 static 변수는 같은 메모리를 재 활용한다는 의미

int main() {
	cout << value << endl;

	int value = 1;
	// 로컬변수는 중괄호를 벗어나는 순간
	// 메모리를 os에게 반환
	// scope, duration도 제한된다.
	
	cout << value << endl;
	// name hiding, shadowing

	cout << ::value << endl;
	// globe scope operator
	// 전역 연산자
	cout << endl;

	doSomething();
	doSomething();
	doSomething();
	doSomething();
	doSomething();
	cout << endl;

	doSomething_static();
	doSomething_static();
	doSomething_static();
	doSomething_static();
	doSomething_static();
	cout << endl;


	cout << "In main.cpp : " << Constants::pi << ", " << &Constants::pi << endl;
	doSomething_in_other_cpp();
}

// 전역변수는 최대한 안 쓰는게 좋다
// 생각치 못한 버그가 떴는데
// 값을 어디서 선언해서 어디서 바꿨는지 등
// 버그 발생지를 추적하기 힘들 수 있다.

// 1) global_a 처럼 이름에 표시를 하던지
// 2) 함수에 파라매터를 직접 써주던지 doSomething(a)