#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	// << left shift
	// >>
	// ~, &, |, ^

	unsigned int a = 3;
	cout << std::bitset<4>(a) << endl;

	unsigned int b = a << 1;
	cout << std::bitset<4>(b) << endl;

	// 곱하기보다 shift operator가 훨씬 빠르다
	// 대신 2가 아닌 일반적인 나누기나 곱하기에서는 사용하지 못한다.

	cout << "a: " << a << endl;
	cout << "a << 1 : " << (a<<1) << endl;
	cout << "a << 2 : " << (a << 2) << endl;
	cout << "a << 3 : " << (a << 3) << endl;
	cout << "a << 4 : " << (a << 4) << endl;

	cout << endl;

	cout << "a: " << a << endl;
	cout << "a >> 1 : " << (a >> 1) << endl;
	cout << "a >> 2 : " << (a >> 2) << endl;
	cout << "a >> 3 : " << (a >> 3) << endl;
	cout << "a >> 4 : " << (a >> 4) << endl;

	cout << endl;
		
	cout << "a " << std::bitset<4>(a) << endl;
	cout << "~a " << std::bitset<4>(~a) << endl;

	cout << endl;


	a = 0b1100; // 2진수 표기법 01xxxx
	b = 0b0110;
	cout << "a " << std::bitset<4>(a) << endl;
	cout << "b " << std::bitset<4>(b) << endl;
	cout << "a&b " << std::bitset<4>(a&b) << endl;
	cout << "a|b " << std::bitset<4>(a|b) << endl;
	cout << "a^b " << std::bitset<4>(a^b) << endl;

	/*
		a += b; 처럼 a &= b 로도 쓸 수 있다.
	*/
	return 0;
}