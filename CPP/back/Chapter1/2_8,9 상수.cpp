#include <iostream>
#include "2_8_9 MY CONTANTS.h"

using namespace std;


// �̷��� �� ���°� ����.
// ������� �����, ��������� �ʹ� �д�.
#define CONST_COST = 30 ; 

void printNumber(const int my_number) {
	my_number = 10;
	// �Ķ���ͷ� �Ѱ��� ���� ���� �ٲ㼭 ����ϴ°�
	// ���� ����

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

	number = 123; // ����
	special_number = 123; // �Ұ���
}

