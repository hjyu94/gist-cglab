#include <cassert>
#include <iostream>
using namespace std;

class MyString
{
public:
	char *m_data = nullptr;
	int m_length = 0;

	// 아니면 애초에 std::string을 쓰는것도 방법
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

	// 복사 생성자
	MyString(const MyString & source)
	{
		cout << "Copy constructor " << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];

			// nullptr가 아니면 나도 새로운 메모리를 할당해서
			// 거기에 값을 대입한다.

			// 멤버변수가 포인터일때 마저도
			// 그 주소값을 그대로 복사해서 가리키는 내용이 지워질수도 있다.

			// 새로운 메모리를 할당해서 가리키는 내용까지 복사해오는 것을 깊은 복사
			// 포인터만 복사해오는 것을 얕은 복사라고 한다.
		}
		else
			m_data = nullptr;
	}

	// 만약 복사 생성자를 만들 여력이 없으면
	// 애초에 delete를 해버리는것도 방법이다.
	// 혹시 shallow copy가 생길지도 모르니까
	// MyString(const MyString & source) = delete;


	// 대입 연산자
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