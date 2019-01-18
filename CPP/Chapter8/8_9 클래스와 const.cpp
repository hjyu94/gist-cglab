#include <iostream>

using namespace std;

class Something
{
public:
	
	int m_value = 0;

	// default copy constructor
	Something(const Something& st_in) {
		m_value = st_in.m_value;
	}

	Something() {
		cout << "constructor" << endl;
	}

	void setValue(int value) { 
		m_value = value; 
	}

	void setValue(int value) const {
		m_value = value;
	}
	// const �Լ������� ��������� ���� �ٲ� �� ����.
	
	int getValue() const 
	{ 
		return m_value; 
	}
	// ��� �Լ��� const��� ����
	// �Լ� ���ο��� ��� ������ ���� �ٲ��� �ʰڴٴ� �ǹ�.
	// ���� const�� ���� �ν������� �ش� �Լ��� ȣ���Ϸ���
	// �ش� �Լ��� const �Լ����� �Ѵ�.

	// ���� const �Լ��� ���� �� ������ ��� const �Լ���
	// ����� ���� ���߿� Ȥ�� const �ν��Ͻ��� ���� ���� ����ؼ�
	// �����ϴ�.
};

void print(Something st) {
	// ���� ����ȴ�
	// �� �� copy constructor�� ȣ��ȴ�.
	cout << &st << endl;
	cout << st.m_value << endl;
}

void print_reference(const Something& st) {
	// ���� ȿ������
	cout << &st << endl;
	cout << st.m_value << endl;
	cout << "�ּҰ� ����" << endl;
}

class Something2 {
public:
	string m_value = "default";
	
	const string& getValue() const { 
		cout << "Const version" << endl;
		return m_value; 
	}

	string& getValue() { 
		cout << "non-const version" << endl;
		return m_value; 
	}
};

int main() {
	// �ν��Ͻ�, ������Ʈ, ���� �����
	const Something something; // ��������� const�� ����
	
	something.setValue(3); 
	// const �ν��Ͻ��� ��������� �ٲٷ��� �ϸ� ������ ����
	
	cout << something.getValue() << endl;
	// ���� ����ϴµ��� ������ ����.
	// const�� �ν��Ͻ��� ��� �Լ��� ȣ���Ϸ���
	// �� ��� �Լ��� const���� �Ѵ�.
	// int getValue() 'const' �� �ٲ�����.
	// const �Լ� �������� ��� ���� �ٲ��� ���� ���̴ٴ� ���� ����ϴ� ��.
	
	// �� instance�� const�� ���� ��쿡��
	// ��� �������� const�� ���������
	// const�� ��� �Լ��鸸 ��� �����ϴ�
	
	// �� : 
	// const�� ���� �� �ִ� �Լ��� const�� ����� ����
	// ���߿� ����뿡 �����ϴ�.

	cout << endl;


	////////////////////////////////////////////////////////////////////////


	Something sth;
	cout << &sth << endl;
	print(something);

	print_reference(sth);

	cout << endl;


	////////////////////////////////////////////////////////////////////////
	

	Something2 sth1;
	sth1.getValue() = 10;

	const Something2 sth2;
	sth2.getValue() = 9999; // ����

}