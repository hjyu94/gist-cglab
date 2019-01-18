#include <iostream>
using namespace std;

class Mother
{
// private:
protected:
	int m_i;

public:
	//Mother()
	//	: m_i(0)
	//{}

	Mother(const int & i_in)
		: m_i(i_in)
	{
		
	}

	void setValue(int input)
	{
		m_i = input;
	}
	
	int getValue()
	{
		return m_i;
	}
};

class Child : public Mother // derived class
{
private:
	double m_d;

public:
	// �������� �뵵��
	// �޸𸮰� �Ҵ�� �� initializer�� ���ּ���
	// �޸𸮰� �Ҵ�� ���� �ű⿡ ���� �־��ּ��䰡 �ƴϴ�.
	// Child�� �����Ҷ� m_i�� �޸𸮰� ���ٴ� ��

	// Child Ŭ������ �����ڸ� ȣ�� �� ��
	// ���������� Mother Ŭ������ �����ڵ� ���� ȣ���Ѵ�.
	// Mother Ŭ������ �����ڸ� ����� ������
	// �⺻ �����ڰ� ������� ���̱� ������
	// Child Ŭ������ �����ڰ� ȣ��ɶ� ����
	// �θ��� �⺻ �����ڰ� �����Ƿ� ������ ����
	// �ذ� -> Mother Ŭ������ �⺻ �����ڸ� ������ش�.
	//      -> �ι�°�� : Mother(i_in), m_d(d_in)
	
	//Child(const int & i_in, const double & d_in)
	//	// : m_i(i_in), m_d(d_in)
	//{
	//	Mother::setValue(i_in);
	//	m_d = d_in;
	//}


	Child(const int & i_in, const double & d_in)
		: Mother(i_in), m_d(d_in)
	{}

	// 
	void setValue(const int & i_in, const double & d_in)
	{
		m_i = i_in; // m_i�� private�� �ƴ� protected�� �ϴ� ���
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double & d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

int main()
{
	Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1024, 128);
	child.Mother::setValue(128);
	cout << child.Mother::getValue() 
		<< ", " << child.getValue() << endl;

}