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

	// ���ϱ⺸�� shift operator�� �ξ� ������
	// ��� 2�� �ƴ� �Ϲ����� �����⳪ ���ϱ⿡���� ������� ���Ѵ�.

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


	a = 0b1100; // 2���� ǥ��� 01xxxx
	b = 0b0110;
	cout << "a " << std::bitset<4>(a) << endl;
	cout << "b " << std::bitset<4>(b) << endl;
	cout << "a&b " << std::bitset<4>(a&b) << endl;
	cout << "a|b " << std::bitset<4>(a|b) << endl;
	cout << "a^b " << std::bitset<4>(a^b) << endl;

	/*
		a += b; ó�� a &= b �ε� �� �� �ִ�.
	*/
	return 0;
}