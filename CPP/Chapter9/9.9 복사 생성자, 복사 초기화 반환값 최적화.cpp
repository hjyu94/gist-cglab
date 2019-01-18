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
		// den�� 0�̸� assert(false)�� ��Ÿ�ӿ��� �߻���Ų��.
	}

	Fraction(const Fraction &fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}

	// ��� ������ �����ε�
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
	// fr_copy�� frac�� �����Ѵ�.
	
	Fraction fr_copy2 = frac;
	// = �� ����� ��쿡�� ���� �����ڰ� ȣ��ȴ�.

	cout << frac << ", " << fr_copy << endl;

	return 0;
}

/****************************************************************/

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	// ���� �����ڸ� private���� �����ϸ�
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
	// fr_copy�� frac�� �����Ѵ�.

	Fraction fr_copy2 = frac; // error
	// = �� ����� ��쿡�� ���� �����ڰ� ȣ��ȴ�.

	Fraction fr_copy(Fraction(3, 10));
	// �� ��쿡�� ���� �����ڰ� ȣ����� �ʴ´�.
	// �����Ϸ��� ���⿡ ���� �����ڸ� ȣ���� �ʿ䰡 ���ٸ� �������⵵ �Ѵ�.

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
	// Debug ��忡���� copy constructor ȣ��
	// Release ��忡���� copy constructor ȣ�� �ȵȴ�.
	// �����Ϸ��� ����ȭ �ɼǿ� �ִ� ��

	cout << &result << endl;
	// Debug��忡���� �ּҰ� �ٸ���. -> ������ ��
	// Release��忡���� �ּҰ� ����. -> �����Ѱ� �ƴ϶� �� ��ü��.
}