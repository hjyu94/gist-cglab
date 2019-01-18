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
	// final로 선언한 함수는 
	// 해당 클래스를 상속받은 자식 클래스에서는 오버라이딩 할 수 없다.
};

