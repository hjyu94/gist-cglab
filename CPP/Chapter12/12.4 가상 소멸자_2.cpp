// ��� �������� �����ڴ� ���� �ڽ� Ŭ������ �ڽ��� �����ڸ� �������. ������ �Ҹ��ڴ� ���� �Ҹ��ڸ� ����ϴ� ���� ����.

#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int *m_array;

public:
	Derived(int length)
	{
		cout << "Derived" << endl;
		m_array = new int[length];
	}

	/*virtual*/ ~Derived() override
		// �Ҹ��ڴ� �Լ����� �ٸ����� �������̵� �ȴ�.
		// virtual�� �������̵� �ϴ� ��� 
		// virtual �� ����� ǥ�����ִ°� ����
		// (�Ⱥٿ��� �Ȱ��� �����ϱ�� ������)
	{
		cout << "~Derived" << endl;
		delete[] m_array;
	}
};

int main()
{
	Derived *derived = new Derived(5);
	Base *base = derived;
	// ������ ���

	delete base;
	// �Ҹ��ڸ� virtual�� ����
	// ~Derived() �ڽ� Ŭ������ �Ҹ��ڵ� ȣ��ǰԲ� �Ѵ�.
	// �� ���Ŀ� ~Base()�� ȣ��ȴ�.
	return 0;
}