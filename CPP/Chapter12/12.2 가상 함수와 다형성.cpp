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

	// [�� ĳ����] �θ��� Ŭ���� Ÿ������ �ڽ� Ŭ������ ��ü�� ����Ű�� ���
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
//	// A::print() �� virtual�� �Ǹ�
//	A &ref = b;
//	ref.print(); // b �� ���´�.
//
//	// B Ŭ������ ������� �ν��Ͻ���
//	// A ���۷����� �ְ� A�� �����Լ��� ȣ���Ҷ�
//	// B ���� �������̵� �� �Լ��� �ִ� �����
//	// A�� �ƴ϶� B Ŭ������ �������̵��� �Լ��� ���
//
//	A &ref = c; 
//	ref.print(); 
//	// A::print() : virtual O
//	// B::print() : virtual X
//	// C::print() : virtual X
//
//	// a �� ����� �ȵɰ� virtual�̴ϱ�
//	// �׷� b�� ��µǷ���? ����
//	// c �� ����� �ȴ�.
//
//	B &ref = c;
//	ref.print();
//	// b�� ��µǴ°� �ƴ϶� c�� ��µȴ�
//	
//	/*
//		class B : public A { ... };
//		class C : public B { ... }; ��
//
//		class B { ... };
//		class C : public B { ... }; �� �ٲٸ� (A<-B ����� ����)
//
//		B &ref = c;
//		ref.print();
//		// �� ���� b�� ��µȴ�.
//	*/
//}
//
///*************************************************/
//
//virtual �Լ��� �ڽ� Ŭ�������� �������̵� �ϸ� ������ �ʾƵ� �ٵ� virtual.
//�׷��� ���� virtual ��� �Լ��� ���� Ŭ������ ��ӹ޴�
//Ŭ���������� �� �Լ��鵵 virtual�� ������ش�.
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