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

	// ~Base()
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
		// �޸� �����Ҵ�
	}
	
	~Derived()
	{
		cout << "~Derived" << endl;
		delete[] m_array;
		m_array = nullptr;
	}
};

int main()
{
	Derived derived(5);
	// �θ�Ŭ������ ������ -> �ڽ�Ŭ������ ������ 
	//    -> �ڽ� Ŭ������ �Ҹ��� -> �θ� Ŭ������ �Ҹ���
	
	// �ڽ�Ŭ������ �Ҹ��ڰ� ȣ��� �� �θ� Ŭ������ �Ҹ��ڰ� ȣ��ȴ�.

	Derived *derived2 = new Derived(5);
	Base *base = derived2;
	// ������ ���
	delete base;
	// Base�� ���� 1���̰� �̸� ��ӹ��� Ŭ�������� ������ �ִ�
	// delete �Ҷ��� Base�� �̿��ؼ� ����°� �򰥸��� �ʴ´�
	// ~Derived()�� ȣ����� �ʰ� ~Base()�� ȣ��ȴ�.
	// �� ĳ���� �ϴ� ��� �θ��� �Լ��� ȣ��Ǳ� ������

	// [������]
	//		�׷��� �̶� ������ delete[] m_array; �� ȣ����� �ʾƼ�
	//		�޸� ���� ������ �����.
	//		�̷����� �Ҹ��ڸ� virtual�� ������ָ� �ȴ�.

	// [�ذ��]
	//		~Base() �Լ��� virtual ~Base()�� �������ָ� �ȴ�.
	
	return 0;
}