// �����Ҵ�� �޸𸮿� ���� ������ ������ ����� ������ �ִ� Ŭ������ ���
// ���縦 �Ҷ� ���� �������� ���� ���������� ����
// ���� ������ ������ ��ٷӴ�.

#include <cassert>
#include <iostream>
using namespace std;

class MyString
{
public:
	char *m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char * source = "")
	{
		assert(source); // ���ڿ��� ����ִ°�
		
		m_length = std::strlen(source) + 1; // '\0'���� �����Ϸ���
		m_data = new char[m_length]; // �����Ҵ�, �� �޸𸮸� ���
		/*
			���� ���� �ּҸ� ����Ű�� �ִ� ������ ������ �޸𸮸� ����������
			���� �޸𸮰� �������� �ϴµ� �������� ���ؼ�
			���ο� �����Ͱ� �ش� �޸𸮸� �����Ѽ� �̻��� ���� ���� �� �ִ�.
			delete�� �� ����� �Ѵ�.
		*/

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];
		
		m_data[m_length - 1] = '\0';

	 } 

	~MyString()
	{
		delete[] m_data;
	}
	
	char* getString() { return m_data; }
	int getLength() { return m_length; }
	
};

int main()
{
	MyString hello("Hello");

	cout << (int *)hello.m_data << endl;
	// �����Ǹ鼭 �Ҵ���� m_data�� �޸� �ּҸ� ��
	// cout ���� char * �� ���ڿ��� �ν��ϱ� ������ int * �� ĳ�����ؼ� ����
	cout << hello.getString() << endl;

	{
		MyString copy = hello;
		// copy�� �����ǰ� �ֱ� ������ ���� �����ڰ� ȣ���
		// ���� �����ϱ� ������ �⺻ ���� �����ڰ� ȣ��ȴ�.

		// copy = hello; // ���� �����ڰ� ȣ���
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}
	// copy�� scope�� ����� �Ҹ��ڰ� ȣ��ȴ�.
	// hello.m_data�� copy.m_data�� ����
	// copy �Ҹ��ڿ��� copy.m_data�� ����Ű�� �޸𸮸� ����������
	
	cout << hello.getString() << endl;
	// ���� �ش� �޸𸮰� �������� �߸��� �����͸� �о���� ��.
}