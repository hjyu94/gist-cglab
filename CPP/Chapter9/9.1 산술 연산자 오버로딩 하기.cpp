#include <iostream>
using namespace std;

class Cents {
private:
	int m_cents;
public:
	// Cents() {}; // 기본 생성자
	Cents(int cents=0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// friend 함수로 오버로딩 하는 방법
	friend Cents operator + (const Cents &c1, const Cents &c2)
	{
	return Cents(c1.getCents() + c2.m_cents);
	}
	// c1.getCents()로 받아오는게 귀찮으면 friend 를 이용하면 된다.
	

	// 멤버 함수로 오버로딩 하는 방법
	// =, [1,2,3,...], (1,2,3,...), -> 는
	// 이런 꼴로만 가능하다.
	Cents operator + (const Cents &c2)
	{
		return Cents(this->m_cents + c2.m_cents);
	}
};

/**********************************************************/
// 연산자 오버로딩 하기 전에 하는 방식

void add(const Cents &c1, const Cents &c2, Cents &c_out) {
	c_out.getCents() = c1.getCents() + c2.getCents();
}

Cents add(const Cents &c1, const Cents &c2) {
	return Cents(c1.getCents() + c2.getCents());
}

/**********************************************************/
// 연산자 오버로딩: 일반 함수로 하는 방법

Cents /*add*/ operator + (const Cents &c1, const Cents &c2) {
	return Cents(c1.getCents() + c2.getCents());
}

/**********************************************************/

int main() {
	Cents cents1(6);
	Cents cents2(8);

	// 기본생성자가 없이 생성자를 오버로딩하면 에러
	// 파라매터에 기본값을 넣어주는 방법도 있다.
	Cents sum;

	add(cents1, cents2, sum);
	cout << sum.getCents() << endl;

	cout << add(cents1, cents2).getCents() << endl;
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;
}