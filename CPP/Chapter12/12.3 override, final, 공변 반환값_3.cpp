#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
	virtual A* getThis() { 
		cout << "A::getThis()" << endl;
		return this; 
	}
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
	virtual B* getThis()  { 
		cout << "B::getThis()" << endl;
		return this; 
	}
	// 원래 리턴 타입이 다르면 오버라이딩이 안 되는데
	// 위와 같이 상속받은 클래스의 주소를 출력하는 경우는 가능
};

int main()
{
	A a;
	B b;
	
	// [업 캐스팅] 부모의 클래스 타입으로 자식 클래스의 객체를 가리키는 경우
	A &ref = b;
	b.getThis()->print(); // B::getThis() B
	ref.getThis()->print(); // B::getThis() A
	// B의 포인터를 리턴하지만 내부적으로 A의 포인터로 바꿔줌

	cout << typeid(b.getThis()).name() << endl; // class B *
	cout << typeid(ref.getThis()).name() << endl; // class A *

}
