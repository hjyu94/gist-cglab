// 동적할당된 메모리에 대한 포인터 변수를 멤버로 가지고 있는 클래스의 경우
// 복사를 할때 깊은 복사인지 얕은 복사인지에 따라
// 복사 생성자 구현이 까다롭다.

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
		assert(source); // 문자열이 비어있는가
		
		m_length = std::strlen(source) + 1; // '\0'까지 저장하려고
		m_data = new char[m_length]; // 동적할당, 힙 메모리를 사용
		/*
			만약 같은 주소를 가리키고 있는 포인터 변수가 메모리를 지워버리면
			힙에 메모리가 지워져야 하는데 지워지지 못해서
			새로운 포인터가 해당 메모리를 가리켜서 이상한 일이 생길 수 있다.
			delete를 잘 해줘야 한다.
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
	// 생성되면서 할당받은 m_data의 메모리 주소를 찍어봄
	// cout 에서 char * 는 문자열로 인식하기 때문에 int * 로 캐스팅해서 보자
	cout << hello.getString() << endl;

	{
		MyString copy = hello;
		// copy가 생성되고 있기 때문에 복사 생성자가 호출됨
		// 아직 구현하기 전으로 기본 복사 생성자가 호출된다.

		// copy = hello; // 대입 생성자가 호출됨
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}
	// copy는 scope를 벗어나면 소멸자가 호출된다.
	// hello.m_data와 copy.m_data가 같음
	// copy 소멸자에서 copy.m_data가 가리키는 메모리를 지워버렸음
	
	cout << hello.getString() << endl;
	// 힙에 해당 메모리가 지워져서 잘못된 데이터를 읽어오게 됨.
}