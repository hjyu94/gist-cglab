#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	void print() { cout << "D" << endl; }
};

int main()
{
	A a;
	B b;
	C c;
	D d;

	// [업 캐스팅] 부모의 클래스 타입으로 자식 클래스의 객체를 가리키는 경우
	A &ref = b; // (A)b
	ref.print(); // A

	A &ref2 = c;
	ref2.print(); // A

	return 0;
}

/*************************************************/
//
//class A
//{
//public:
//	virtual void print() { cout << "a" << endl; }
//};
//
//class B : public A
//{
//public:
//	void print() { cout << "b" << endl; }
//};
//
//int main()
//{
//	A a;
//	B b;
//	C c;
//	D d;
//	
//	// A::print() 가 virtual이 되면
//	A &ref = b;
//	ref.print(); // b 가 나온다.
//
//	// B 클래스로 만들어진 인스턴스를
//	// A 레퍼런스에 넣고 A의 가상함수를 호출할때
//	// B 에서 오버라이딩 된 함수가 있는 경우라면
//	// A가 아니라 B 클래스의 오버라이딩된 함수를 사용
//
//	A &ref = c; 
//	ref.print(); 
//	// A::print() : virtual O
//	// B::print() : virtual X
//	// C::print() : virtual X
//
//	// a 는 출력이 안될것 virtual이니까
//	// 그럼 b가 출력되려나? ㄴㄴ
//	// c 가 출력이 된다.
//
//	B &ref = c;
//	ref.print();
//	// b가 출력되는게 아니라 c가 출력된다
//	
//	/*
//		class B : public A { ... };
//		class C : public B { ... }; 를
//
//		class B { ... };
//		class C : public B { ... }; 로 바꾸면 (A<-B 상속을 끊음)
//
//		B &ref = c;
//		ref.print();
//		// 이 경우는 b가 출력된다.
//	*/
//}
//
///*************************************************/
//
//virtual 함수를 자식 클래스에서 오버라이딩 하면 써주지 않아도 다들 virtual.
//그래서 보통 virtual 멤버 함수를 갖는 클래스를 상속받는
//클래스에서는 각 함수들도 virtual로 만들어준다.
//
//class A
//{
//public:
//	virtual void print() { cout << "A" << endl; }
//};
//
//class B : public A
//{
//public:
//	virtual void print() { cout << "B" << endl; }
//};
//
//class C : public B
//{
//public:
//	virtual void print() { cout << "C" << endl; }
//};
//
//class D : public C
//{
//public:
//	virtual void print() { cout << "D" << endl; }
//};