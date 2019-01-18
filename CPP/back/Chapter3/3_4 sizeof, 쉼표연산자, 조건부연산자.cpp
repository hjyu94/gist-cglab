#include <iostream>

using namespace std;

int main() {
	float a;
	
	// 1. sizeof�� �Լ��� �ƴ϶� �������̴�.
	cout << sizeof(float) << endl; // ������ Ÿ��(class, struct ����)
	cout << sizeof(a) << endl; // ����
	cout << sizeof a << endl; // ����

	// 2. comma operator
	int x = 3;
	int y = 10;
	int z = (++x, ++y); // ���� ++x; ++y; z = y; �̷��� ���µ� �ݺ��������� comma operator�� ���� ����Ѵ�.

	cout << x << ", " << y << ", " << z << endl;

	int a = 1, b = 10;
	// �� ���� comma operator�� �ƴϴ�. �켱���� �����ε�, =�� �켱������ , ���� ���Ƽ�
	// (z=a), b �� ��찡 �ȴ�.
	z = a, b; 
	cout << z << endl;

	z = (++a, a + b);
	cout << z << endl;


	// 3. conditional operator, arithmetric if
	// 3�� ������

	bool onSale = true;
	int price;
	if (onSale)
		price = 10;
	else
		price = 100;

	// �׷��� price�� ����� ���� �ʹٸ�?
	// �̶� conditional operator�� ���� �ȴ�!
	const int price = (onSale == true) ? 10 : 100;

	// Ȥ�� �Լ��� ���� ���� �ٸ� return���� �޾ƿ� �� �ִ�.
	const int price = getPrice(onSale);

	return 0;
}