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

	// ��� ������ �����ε�
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
		�̸� ���� doSomething(7)���� ��������. ����ȯ �ȵ�
	*/

	Fraction frac('c'); 
	// �̷��Դ� �����ϸ� �ȵȴ�
	// �ڵ� ����ȯ�� �Ǵ� ���� �����ϴ� ��� ���

	return 0;
}