#include <cassert>
#include <iostream>
using namespace std;

class MyString
{
public:
	char *m_data = nullptr;
	int m_length = 0;

	// �ƴϸ� ���ʿ� std::string�� ���°͵� ���
	// std::string data;

public:
	MyString(const char * source = "")
	{
		assert(source);

		m_length = std::strlen(source) + 1; 
		m_data = new char[m_length]; 

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

	// ���� ������
	MyString(const MyString & source)
	{
		cout << "Copy constructor " << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];

			// nullptr�� �ƴϸ� ���� ���ο� �޸𸮸� �Ҵ��ؼ�
			// �ű⿡ ���� �����Ѵ�.

			// ��������� �������϶� ������
			// �� �ּҰ��� �״�� �����ؼ� ����Ű�� ������ ���������� �ִ�.

			// ���ο� �޸𸮸� �Ҵ��ؼ� ����Ű�� ������� �����ؿ��� ���� ���� ����
			// �����͸� �����ؿ��� ���� ���� ������ �Ѵ�.
		}
		else
			m_data = nullptr;
	}

	// ���� ���� �����ڸ� ���� ������ ������
	// ���ʿ� delete�� �ع����°͵� ����̴�.
	// Ȥ�� shallow copy�� �������� �𸣴ϱ�
	// MyString(const MyString & source) = delete;


	// ���� ������
	MyString& operator = (const MyString & source)
	{
		/*
			// shallow copy
			this->m_data = source.m_data;
			this->m_length = source.m_length;
		*/

		cout << "Assignment operator " << endl;

		if (this == &source) // prevent self-assignment
			return *this;
		
		delete[] m_data;
		
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}
};

int main()
{
	MyString hello("Hello");

	cout << (int *)hello.m_data << endl;
	cout << hello.getString() << endl;
	{
		MyString copy = hello;

		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}

	cout << hello.getString() << endl;

	MyString hi;
	hi = hi; // prevent self-assignment
	
	cout << endl;

	MyString str1 = hello; // copy constructor
	MyString str2;
	str2 = hello; // assign constructor

}