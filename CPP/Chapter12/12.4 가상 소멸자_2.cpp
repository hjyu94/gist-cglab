// 상속 구조에서 생성자는 보통 자식 클래스의 자신의 생성자를 사용했음. 하지만 소멸자는 가상 소멸자를 사용하는 것이 좋다.

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
		// 소멸자는 함수명이 다르더라도 오버라이딩 된다.
		// virtual을 오버라이딩 하는 경우 
		// virtual 을 명백히 표시해주는게 좋다
		// (안붙여도 똑같이 동작하기는 하지만)
	{
		cout << "~Derived" << endl;
		delete[] m_array;
	}
};

int main()
{
	Derived *derived = new Derived(5);
	Base *base = derived;
	// 다형성 사용

	delete base;
	// 소멸자를 virtual로 만들어서
	// ~Derived() 자식 클래스의 소멸자도 호출되게끔 한다.
	// 이 이후에 ~Base()도 호출된다.
	return 0;
}