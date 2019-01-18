#include <iostream>
using namespace std;

class Something
{
public:
	class _init {
	public:
		_init() {
			s_value = 1234;
		}
	};

/*public->*/ private:
	static int s_value;
	int m_value;

	static _init s_initializer;

public:
	Something()
		: m_value(123), s_value(1024)
	{}

	static int getValue() 
	{
		return s_value;
		// return this->s_value;
		// return m_value;
		// static 함수에선 this 포인터를 사용할 수 없다.
	}

	int temp() {
		return this->s_value;
	}
};

int Something::s_value = 1024;
Something::_init Something::s_initializer; // 인스턴스 생성

int main() 
{
	cout << Something::getValue() << endl;
	
	Something s1;
	cout << s1.getValue() << endl;
	// cout << s1.s_value << endl;

	// 함수 포인터
	// 멤버 함수의 포인터
	
	// int (Something::*fptr1)() = &(s1.temp);
	// 멤버 변수는 s1에 묶여 있따.
	// s1, s2의 m_value는 주소가 다르다
	// 그런데 함수는 주소가 같다
	// 각 인스턴스마다 함수를 만들어주는게 아니라
	// 어느 위치에 Something 클래스의 temp 함수 하나만 만든다.
	// s1.temp()를 실행할때 s1의 주소를(this) 넘겨서 실행하는 꼴

	int (Something::*fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl;
	// non static function은 인스턴스에 종속된 형태이므로
	// this pointer를 넘겨주기 위해 s2.*fptr1 과 같이
	// 함수 포인터 앞에 해당 인스턴스를 써주어야 한다.
	// this pointer를 넘겨줘야만 하므로

	// 그러나 static 함수는 해당 인스턴스에 종속성이 업으므로
	// Something:: 을 떼서 선언해야 한다.
	int ( /*Something::*/ *fptr2)() = &Something::getValue;

}

// 1
s_value가 public이었다가 private으로 바뀌면
s1.s_value나 Something::s_value로는 접근이 불가능하다.
인스턴스 s1가 있다면 s1.getValue()로 접근하면 되지만
인스턴스를 만들지 않은 상태에서는 정적 멤버 변수를 접근하기 위해선
getValue()를 static으로 바꾸면 된다.

cout << Something::s_value << endl; 대신에
cout << Something::getValue() << endl; 를 사용하자.


// 2
this로 접근해야 하는 모든것이 안된다.

static int getValue()
{
	return s_value;
	// return this->s_value;
	// return m_value;
	// static 함수에선 this 포인터를 사용할 수 없다.
}

// 3 
함수 포인터에서의 사용
int( /*Something::*/ *fptr2)() = &Something::getValue;

static 함수는 this pointer가 필요 없기 때문이다.


// 4
static 멤버 변수는 생성자에서 초기화시켜줄 수 없다.
생성자가 static 함수여야 static 멤버 변수에 값을 줄 수 있다.
-> inner Class를 만들어서 걔의 생성자에서 값을 주는 방법은 있다.