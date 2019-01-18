#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A constructor" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}
};


class C : public B
{
public:
	C()
	{
		cout << "C constructor" << endl;
	}
};

int main()
{
	C c;
	// 할머니 - 엄마 - 나 순으로 생성자 호출
}