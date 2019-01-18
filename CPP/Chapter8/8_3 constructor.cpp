#include <iostream>
using namespace std;

class Fraction {
public:
	int m_numerator;
	int m_denominator;

public:
	// 생성자가 아무것도 없을 때
	// Fraction() {} 
	// default constructor : construction 될때 자동으로 호출되는 함수

	Fraction(const int& numerator_input=1, const int& denominatro_input=1) {
		cout << "constructor start" << endl;
		m_numerator = numerator_input;
		m_denominator = denominatro_input;
		cout << "constructor finished" << endl;
	}

	void print() {
		cout << m_numerator << " / " << m_denominator << endl;
	}
};


class Second {
public:
	Second() {
		cout << "Second constructor()" << endl;
	}
};

class First {
	Second sec;

public:
	First() {
		cout << "First constructor()" << endl;
	}
};

int main() {
	// 생성자가 인스턴스를 만드는 것은 아님
	// 이름의 뉘앙스 때문에 헷갈리면 안됨
	// construction 될때 자동으로 호출되는 함수

	Fraction frac(1,3);
	// 멤버 변수에 순서대로 1, 3을 넣어준다
	frac.print();

	// 파라매터가 없는 경우에는 frac() 이렇게 쓰면 안되고 frac 으로 쓴다
	// 생성자를 하나라도 만들어주면 기본 생성자를 호출하지 않기 때문이다.
	// 이를 해결하려면 기본 생성자를 만들어 주면 된다.
	Fraction frac2;
	frac2.print();
	
	cout << endl;

	// 클래스 내에 다른 클래스 타입의 멤버변수를 추가한다.
	// 이 경우 멤버 변수 -> 멤버 함수
	// Second 생성자 호출 -> First 생성자 호출 순서이다.
	First fir;

	return 0;
}