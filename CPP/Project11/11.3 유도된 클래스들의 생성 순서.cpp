#include <iostream>
using namespace std;

class Mother
{
public:
	int m_i;
};

class Child : public Mother
{
public:
	/*
		Child()
		{
			m_i = 10;
			this->m_i = 10; // ������! �� ���� ǥ��
			Mother::m_i = 1024; // ����� ���� ����
			this->Mother::m_i = 1024;
		}
	*/
	
	Child()
		: m_i(1024);
	{

	}
	// Mother���� ��ӹ޾Ҵµ� �� �ʱ�ȭ�� �� �Ǵ°ɱ�
};

/*************************************************************/

class Mother
{
public:
	int m_i;

	Mother()
		: m_i(1)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

public:
	Child()
		: m_d(1.0)
	{
		cout << "Child construction" << endl;
	}
};

int main()
{
	Child c1;
	// ��� ���
	// Mother construction
	// Child construction

	// Mother�� �ִ� �͵��� ��� �ʱ�ȭ �� �Ŀ�
	// Child�� �����Ѵ�
	
	// ������غ��� ���� ����
	// 54 - 41 - 40 - 42 - 43 - 53 - 55 - 56
	// initializer �Ҷ� �ش� ������ �޸𸮰� �������� �ʾƼ�
	// �ڽ� Ŭ�������� �θ� ������ �ʱ�ȭ �� �� ����.
}

/*************************************************************/

class Mother
{
public:
	int m_i;

	Mother(const int & i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

public:
	Child()
		: Mother(), m_d(1.0)
		// ������ ��ó�� �θ��� �����ڸ� �θ��� ��.
	{
		cout << "Child construction" << endl;
	}
};

/*************************************************************/

class Mother
{
public:
	int m_i;

	Mother(const int & i_in )
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}

	// = 0 ���� ���ָ� ����Ʈ �������� ���ҵ� ���� �Ѵ�.
	// �ѹ��� �ذ�!
	Mother(const int & i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

public:
	Child()
		: Mother(1024), m_d(1.0)
	{
		cout << "Child construction" << endl;
	}
};
