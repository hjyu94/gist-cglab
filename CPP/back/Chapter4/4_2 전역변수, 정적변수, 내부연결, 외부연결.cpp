/*
	int g_x; // external linkage �ʱ�ȭ�� �ȵ� ��������
	static int g_x; // internal linkage �ٸ� cpp���Ͽ��� ������ �� ���� �ʱ�ȭ���� ���� ���������̴�.
	const int g_x ; // const�� ���� ������ ������ �ȵȴ�.

	extern int g_z;
	extern const int g_x; 
	// �ٸ� �� ��𼭴� �� ���� ������ �ʱ�ȭ ������ �Ѵ�.

	int g_y(1);
	static int g_y(1); // �ٸ� ������ ��� �Ұ���
	const int g_y(1); // ���� ���� �ȿ����� ���

	extern int g_w(1); // �ٸ� �������� �ʱ�ȭ ���ָ� �ȵȴ�.
	extern const int g_w(1); // �ٸ� cpp���Ͽ��� ��� ����

	���Ҹ���...?
*/

#include <iostream>
#include "4_2 MyConstants.h"

using namespace std;

// forward declaration

// �ٸ� cpp ���� ��򰡿� �� �Լ��� ���ǰ� �����ϴϱ�
// ��ŷ�� �� ������ ���̼��� ��� �ǹ�
// #include "4_2 test.cpp" ó�� �� ���� ������ �̴� ����

// �� �� extern�� ���� �����ϴ�.
extern void doSomething_in_other_cpp();

// �������� �� �� �׷� ok ��� �ְ��� �ߴµ�
// ��ŷ�Ϸ��� ���ϱ� obj ������ ���� ������
// ���ǵ� ���� ����. �޸𸮰� ����.
// ���⼭ ������ �ʱ�ȭ�� �ȵ��־��ٴ� �� -> �ʱ�ȭ ���� ���ش�.
extern int extern_a;

int value = 123;

void doSomething() {
	int a = 1;
	++a;
	cout << a << endl;
}

void doSomething_static() {
	/*
		�̷��� ���� ���õ�
		static ������ ����� ���ÿ� �ʱ�ȭ �Ǿ�� �Ѵ�

		static int a;
		a = 1;
	*/

	static int a = 1; 
	// static�� �ѹ� �ʱ�ȭ�Ǹ� �ι�° �ʱ�ȭ ��ɹ��� �����ϰ� �Ѿ��.
	// ��ġ ���������� int a = 1;�� �ð� ����.
	++a;
	cout << a << endl;
}
// static duration var.
// static: ���� a�� �޸𸮷κ��� ���� �޸�
// �� static ������ ���� �޸𸮸� �� Ȱ���Ѵٴ� �ǹ�

int main() {
	cout << value << endl;

	int value = 1;
	// ���ú����� �߰�ȣ�� ����� ����
	// �޸𸮸� os���� ��ȯ
	// scope, duration�� ���ѵȴ�.
	
	cout << value << endl;
	// name hiding, shadowing

	cout << ::value << endl;
	// globe scope operator
	// ���� ������
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

// ���������� �ִ��� �� ���°� ����
// ����ġ ���� ���װ� ���µ�
// ���� ��� �����ؼ� ��� �ٲ���� ��
// ���� �߻����� �����ϱ� ���� �� �ִ�.

// 1) global_a ó�� �̸��� ǥ�ø� �ϴ���
// 2) �Լ��� �Ķ���͸� ���� ���ִ��� doSomething(a)