#include <iostream>
using namespace std;

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x*y; }

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0~2: add subtract multiply" << endl;

	/******************************************/

	// static binding (early binding)
	int result;
	switch (op)
	{
	case 0:
		result = add(x, y); break;
	case 1:
		result = subtract(x, y); break;
	case 2:
		result = multiply(x, y); break;
	}

	cout << result << endl;
	
	/******************************************/

	// dynamic binding (late binding)
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0:
		func_ptr = add; break;
	case 1:
		func_ptr = subtract; break;
	case 2:
		func_ptr = multiply; break;
	}

	cout << func_ptr(x, y) << endl;
	
	// func_ptr�� � �Լ��� �ּҰ� �� ��
	// ��Ÿ�ӿ� ���� �ȴ�.
	
	// ���� ���س���(func_ptr(x,y))�� �������� �Ҵ�� �ּҸ� ã�ư���
	// �ּ� �ڸ��� �ִ� �Լ��� ����� ���� ã�� 
	// �������� ����� ����ϰ� �ִ�.

	/******************************************/

	return 0;
}

/*			static binding		dynamic binding
	�ӵ�			������				������
	������		����					����
*/

// ������ ���α׷����� �ʿ��Ҷ� ���� ���ε��� �ſ� �����ϴ�