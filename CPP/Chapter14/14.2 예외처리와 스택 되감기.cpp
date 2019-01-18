/*
	����ó���� ���� �ǰ���(Stack unwinding)

	�Լ��� �Լ��� ȣ���ϰ�, �� �Լ� ������ �ٸ� �Լ��� ȣ���Ѵٸ�
	���ÿ� �Լ����� ��/ ��/ ��/ �׿������� �ȴ�.

	���� ���ʿ� �ִ� �Լ��� ���ܸ� �����ٸ�
	������ �ǰ��ư��鼭 ��� ���ܸ� ������ ã�� �ȴ�.

	���� ���ϸ� ������ �ǰ��� �ϸ鼭 ��� ���󰣴�
*/

#include <iostream>
using namespace std;

/*
	void last() throw(data type) exception specifier
	data type�� int�� ���� char�� ����
	void last() throw(...) exception specifier
	�� ���ٰ� ó���Ѵ�

	���ܸ� ó���� �� �ִ� �Լ��ٴ� �� �˷��ֱ� ���ؼ� ����ϱ� ��
	�� �ɷ��� ����

	��, ��ĭ���� �θ� �ȵ�
	void last() throw() exception specifier
	�� �� �Լ��� ���ܸ� �� �����ſ���! ��� ǥ��

	void last() throw(int)
	{ 
		... 
	}
*/
void last()
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;

	throw - 1;

	cout << "End last" << endl;
}

void third()
{
	cout << "Third" << endl;

	last();
	
	cout << "End third" << endl; // 1 ���� �ȵ�
}

void second()
{
	cout << "Second" << endl;
	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught int exception" << endl;
	}

	// catch �� ������ �ش��ϴ� data type�� ��� ��찡 ���
	// �� ����

	cout << "End second " << endl; // 2 ���� �ȵ�
}

void first()
{
	cout << "First" << endl;
	try
	{
		second();
	}
	//catch (int) // ���� ���⼭ ����
	//{
	//	cerr << "First caught int exception" << endl;
	//}
	catch (int *)
	{
		cerr << "First caught int exception" << endl;
	}

	cout << "End first " << endl;
}

int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		// std::cout, std::cerr, std::clog
		// �ֿܼ� ������ ����ϴ� ä���� ���������� �ִٰ� �˸� ��

		cerr << "main caught int exception" << endl;
	}

	// uncaught exceptions
	catch (...) // catch-all handlers ������ ����
	{
		cerr << "main caught ellipses exception" << endl;
	}
	cout << "End main" << endl;

	return 0;
}
