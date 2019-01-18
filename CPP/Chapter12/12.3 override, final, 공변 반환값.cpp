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

	// 부모의 클래스 타입으로 자식 클래스의 객체를 가리키는 경우
	// 업 캐스팅!
	A &ref = b; 
	ref.print(1); // B
	// print()를 virtual 함수로 만들었기 때문에 
	// B가 출력된다.
}

/*****************************************************************/

// 근데 실수로 B::print()의 파라매터 데이터 타입을 다르게 지정하게 되면
class A
{
public:
	virtual void print(int x) { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print(short x) { cout << "B" << endl; }
	// 파라매터가 int가 아니라 short
	// 파라매터가 다르면 오버라이딩을 할 수가 없다.
};

int main()
{
	A a;
	B b;

	A &ref = b;
	ref.print(1); // A
	// print를 virtual 함수로 만들었기 때문에 
	// B가 출력되길 바랬는데
	// 실수로 파라매터를 int가 아니라 short로 만들면
	// A가 출력된다.
	// 오버라이딩 된 것이 아니기 떄문 
}

/*****************************************************************/

// 자식 클래스에서 어떤 함수를 구현할 때 
// virtual 함수를 오버라이딩 하고 싶은 거라면 override라고 치면
// 컴파일 에러를 미리 찾아주는 역할을 한다. 

// 잘못 치는 경우 빨간줄 쫙~
// 오버라이딩 하고 싶어하는건 알겠는데 파라매터 타입이 달라서
// 오버라이딩이 안돼! 알려주는 것.

class A
{
public:
	virtual void print(int x) { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print(short x) override { cout << "B" << endl; }
	// override 라고 명백히 적어줄 수 있다.
};

int main()
{
	A a;
	B b;

	A &ref = b;
	ref.print(1);
}
