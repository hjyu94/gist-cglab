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
	// ���� ���� Ÿ���� �ٸ��� �������̵��� �� �Ǵµ�
	// ���� ���� ��ӹ��� Ŭ������ �ּҸ� ����ϴ� ���� ����
};

int main()
{
	A a;
	B b;
	
	// [�� ĳ����] �θ��� Ŭ���� Ÿ������ �ڽ� Ŭ������ ��ü�� ����Ű�� ���
	A &ref = b;
	b.getThis()->print(); // B::getThis() B
	ref.getThis()->print(); // B::getThis() A
	// B�� �����͸� ���������� ���������� A�� �����ͷ� �ٲ���

	cout << typeid(b.getThis()).name() << endl; // class B *
	cout << typeid(ref.getThis()).name() << endl; // class A *

}
