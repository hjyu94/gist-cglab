// final

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print(int x) final { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print(int x) { cout << "B" << endl; }
	// final�� ������ �Լ��� 
	// �ش� Ŭ������ ��ӹ��� �ڽ� Ŭ���������� �������̵� �� �� ����.
};

