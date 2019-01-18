#include <iostream>
using namespace std;

class Mother
{
public:
	int m_i;
};

class Child : public Mother
{
public:
	/*
		Child()
		{
			m_i = 10;
			this->m_i = 10; // 내꺼다! 의 강한 표현
			Mother::m_i = 1024; // 상속의 개념 강조
			this->Mother::m_i = 1024;
		}
	*/
	
	Child()
		: m_i(1024);
	{

	}
	// Mother에서 상속받았는데 왜 초기화는 안 되는걸까
};

/*************************************************************/

class Mother
{
public:
	int m_i;

	Mother()
		: m_i(1)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

public:
	Child()
		: m_d(1.0)
	{
		cout << "Child construction" << endl;
	}
};

int main()
{
	Child c1;
	// 출력 결과
	// Mother construction
	// Child construction

	// Mother에 있는 것들을 모두 초기화 한 후에
	// Child를 생성한다
	
	// 디버깅해보면 실행 순서
	// 54 - 41 - 40 - 42 - 43 - 53 - 55 - 56
	// initializer 할때 해당 변수의 메모리가 잡혀있지 않아서
	// 자식 클래스에서 부모 변수를 초기화 할 수 없다.
}

/*************************************************************/

class Mother
{
public:
	int m_i;

	Mother(const int & i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

public:
	Child()
		: Mother(), m_d(1.0)
		// 원래는 이처럼 부모의 생성자를 부르는 것.
	{
		cout << "Child construction" << endl;
	}
};

/*************************************************************/

class Mother
{
public:
	int m_i;

	Mother(const int & i_in )
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}

	// = 0 까지 해주면 디폴트 생성자의 역할도 같이 한다.
	// 한번에 해결!
	Mother(const int & i_in = 0)
		: m_i(i_in)
	{
		cout << "Mother construction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

public:
	Child()
		: Mother(1024), m_d(1.0)
	{
		cout << "Child construction" << endl;
	}
};
