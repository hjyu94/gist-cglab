#include <iostream>
#include "4_2 MyConstants.h"

// extern int a ;
extern int extern_a = 12345;

void doSomething_in_other_cpp() {
	using namespace std;

	cout << "In test.cpp : " << Constants::pi << ", " << &Constants::pi << endl;
	cout << "���� �ּҰ� �ٸ��� ����, ����� ��û���� ���� ���� �޸� ���� �ȴ�" << endl;
	cout << "�ذ��-> ������� ���Ǹ� ����� cpp������ ���� ���� �� extern���� �����Ѵ�" << endl;
}