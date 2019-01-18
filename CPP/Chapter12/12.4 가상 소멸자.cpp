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
		// 메모리 동적할당
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
	// 부모클래스의 생성자 -> 자식클래스의 생성자 
	//    -> 자식 클래스의 소멸자 -> 부모 클래스의 소멸자
	
	// 자식클래스의 소멸자가 호출된 후 부모 클래스의 소멸자가 호출된다.

	Derived *derived2 = new Derived(5);
	Base *base = derived2;
	// 다형성 사용
	delete base;
	// Base는 보통 1개이고 이를 상속받은 클래스들이 여러개 있다
	// delete 할때도 Base를 이용해서 지우는게 헷갈리지 않는다
	// ~Derived()는 호출되지 않고 ~Base()만 호출된다.
	// 업 캐스팅 하는 경우 부모의 함수가 호출되기 때문에

	// [문제점]
	//		그런데 이때 문제는 delete[] m_array; 가 호출되지 않아서
	//		메모리 누수 문제가 생긴다.
	//		이럴때는 소멸자를 virtual로 만들어주면 된다.

	// [해결법]
	//		~Base() 함수를 virtual ~Base()로 변경해주면 된다.
	
	return 0;
}