#pragma once // 헤더가드
#include <iostream>

// 헤더파일에 선언만 쫙 모아놓으면 보기 깔끔하다.

class Calc {
private:
	int m_value;
public:
	Calc(int init_value);

	void add(int value);
	void sub(int value);
	void mult(int value);
	void print();
};
