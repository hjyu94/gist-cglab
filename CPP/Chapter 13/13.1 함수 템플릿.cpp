// ���ø�: �������� �ڷ����� ���� ���� ����� �ڵ带 �ۼ��ϴ°��� �������ش�.

#include <iostream>
#include "Cents.h"
// user defined class�� T �ڸ��� ���� �� �ִ�.

/*************************************/

int getMax(int x, int y) {
	return (x > y) ? x : y;
}

double getMax(double x, double y) {
	return (x > y) ? x : y;
}

char getMax(char x, char y) {
	return (x > y) ? x : y;
}

/*************************************/
/*
template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}
*/

template<class T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

/*************************************/

int main()
{
	using namespace std;
	cout << getMax(1, 2) << endl; // int
	cout << getMax(3.14, 2.253) << endl; // double
	cout << getMax(1.0f, 3.4f) << endl; // float
	cout << getMax('a', 'c') << endl; // char
	cout << getMax(Cents(3), Cents(5)) << endl; // char
	// Cents class�� output operator�� �����ε� �Ǿ����� �ʾƼ�

	// cout << getMax(1, 'a') << end; // error
}