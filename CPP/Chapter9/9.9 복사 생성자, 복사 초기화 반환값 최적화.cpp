#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
		// den이 0이면 assert(false)로 런타임에러 발생시킨다.
	}

	Fraction(const Fraction &fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	// 출력 연산자 오버로딩
	friend std::ostream & operator << (std::ostream & out, const Fraction & f)
	{
		cout << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

int main()
{
	Fraction frac(3, 6);

	Fraction fr_copy(frac);
	// fr_copy에 frac를 복사한다.
	
	Fraction fr_copy2 = frac;
	// = 를 사용한 경우에도 복사 생성자가 호출된다.

	cout << frac << ", " << fr_copy << endl;

	return 0;
}

/****************************************************************/

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	// 복사 생성자를 private으로 선언하면
	Fraction(const Fraction &fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}
};

int main()
{
	Fraction frac(3, 6);

	Fraction fr_copy(frac); // error
	// fr_copy에 frac를 복사한다.

	Fraction fr_copy2 = frac; // error
	// = 를 사용한 경우에도 복사 생성자가 호출된다.

	Fraction fr_copy(Fraction(3, 10));
	// 이 경우에는 복사 생성자가 호출되지 않는다.
	// 컴파일러가 보기에 복사 생성자를 호출할 필요가 없다면 빼버리기도 한다.

	cout << frac << ", " << fr_copy << endl;

	return 0;
}

/****************************************************************/

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}

int main()
{
	Fraction result = doSomething();
	// Debug 모드에서는 copy constructor 호출
	// Release 모드에서는 copy constructor 호출 안된다.
	// 컴파일러의 최적화 옵션에 있는 것

	cout << &result << endl;
	// Debug모드에서는 주소가 다르다. -> 복사한 것
	// Release모드에서는 주소가 같다. -> 복사한게 아니라 걔 자체임.
}