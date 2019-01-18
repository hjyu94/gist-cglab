#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(char) = delete;

	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
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

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	doSomething(Fraction(7));
	doSomething(7);
	
	/*
		explicit Fraction(int num = 0, int den = 1)
			: m_numerator(num), m_denominator(den)
		{
			assert(den != 0);
		}
		이면 쓰면 doSomething(7)에서 에러난다. 형변환 안됨
	*/

	Fraction frac('c'); 
	// 이렇게는 생성하면 안된다
	// 자동 형변환이 되는 것을 염려하는 경우 사용

	return 0;
}