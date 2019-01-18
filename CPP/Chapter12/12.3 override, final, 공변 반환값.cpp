#include <iostream>
using namespace std;

class A
{
public:
	virtual void print(int x) { cout << "A" << endl; }
};

class B : public A
{ 
public:
	virtual void print(int x) { cout << "B" << endl; }
};

int main()
{
	A a;
	B b;

	// �θ��� Ŭ���� Ÿ������ �ڽ� Ŭ������ ��ü�� ����Ű�� ���
	// �� ĳ����!
	A &ref = b; 
	ref.print(1); // B
	// print()�� virtual �Լ��� ������� ������ 
	// B�� ��µȴ�.
}

/*****************************************************************/

// �ٵ� �Ǽ��� B::print()�� �Ķ���� ������ Ÿ���� �ٸ��� �����ϰ� �Ǹ�
class A
{
public:
	virtual void print(int x) { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print(short x) { cout << "B" << endl; }
	// �Ķ���Ͱ� int�� �ƴ϶� short
	// �Ķ���Ͱ� �ٸ��� �������̵��� �� ���� ����.
};

int main()
{
	A a;
	B b;

	A &ref = b;
	ref.print(1); // A
	// print�� virtual �Լ��� ������� ������ 
	// B�� ��µǱ� �ٷ��µ�
	// �Ǽ��� �Ķ���͸� int�� �ƴ϶� short�� �����
	// A�� ��µȴ�.
	// �������̵� �� ���� �ƴϱ� ���� 
}

/*****************************************************************/

// �ڽ� Ŭ�������� � �Լ��� ������ �� 
// virtual �Լ��� �������̵� �ϰ� ���� �Ŷ�� override��� ġ��
// ������ ������ �̸� ã���ִ� ������ �Ѵ�. 

// �߸� ġ�� ��� ������ ��~
// �������̵� �ϰ� �;��ϴ°� �˰ڴµ� �Ķ���� Ÿ���� �޶�
// �������̵��� �ȵ�! �˷��ִ� ��.

class A
{
public:
	virtual void print(int x) { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print(short x) override { cout << "B" << endl; }
	// override ��� ����� ������ �� �ִ�.
};

int main()
{
	A a;
	B b;

	A &ref = b;
	ref.print(1);
}
