#include <iostream>
using namespace std;

class Mother
{
// private:
protected:
	int m_i;

public:
	//Mother()
	//	: m_i(0)
	//{}

	Mother(const int & i_in)
		: m_i(i_in)
	{
		
	}

	void setValue(int input)
	{
		m_i = input;
	}
	
	int getValue()
	{
		return m_i;
	}
};

class Child : public Mother // derived class
{
private:
	double m_d;

public:
	// 생성자의 용도는
	// 메모리가 할당될 때 initializer를 해주세요
	// 메모리가 할당된 이후 거기에 값을 넣어주세요가 아니다.
	// Child를 생성할때 m_i의 메모리가 없다는 것

	// Child 클래스의 생성자를 호출 할 때
	// 내부적으로 Mother 클래스의 생성자도 같이 호출한다.
	// Mother 클래스의 생성자를 만들어 버리면
	// 기본 생성자가 사라지는 꼴이기 때문에
	// Child 클래스의 생성자가 호출될때 사용될
	// 부모의 기본 생성자가 없으므로 컴파일 에러
	// 해결 -> Mother 클래스의 기본 생성자를 만들어준다.
	//      -> 두번째는 : Mother(i_in), m_d(d_in)
	
	//Child(const int & i_in, const double & d_in)
	//	// : m_i(i_in), m_d(d_in)
	//{
	//	Mother::setValue(i_in);
	//	m_d = d_in;
	//}


	Child(const int & i_in, const double & d_in)
		: Mother(i_in), m_d(d_in)
	{}

	// 
	void setValue(const int & i_in, const double & d_in)
	{
		m_i = i_in; // m_i를 private이 아닌 protected로 하는 경우
		Mother::setValue(i_in);
		m_d = d_in;
	}

	void setValue(const double & d_in)
	{
		m_d = d_in;
	}

	double getValue()
	{
		return m_d;
	}
};

int main()
{
	Mother mother;
	mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1024, 128);
	child.Mother::setValue(128);
	cout << child.Mother::getValue() 
		<< ", " << child.getValue() << endl;

}