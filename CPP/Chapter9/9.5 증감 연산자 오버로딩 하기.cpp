#include <iostream>

using namespace std;

class Digit
{
private:
	int m_digit;
	
public:
	Digit(int digit = 0)
		: m_digit(digit) {}
	
	Digit& operator ++ () // prefix
	{
		++m_digit;
		return *this;
	}

	Digit operator ++ (int) // postfix, dummy var.
	{
		Digit temp(m_digit);
		++(this->m_digit);
		return temp;
	}

	friend std::ostream& operator << (std::ostream &out, const Digit &digit) {
		out << digit.m_digit;
		return out; // chaining
	}
};

int main()
{
	Digit d(5);
	
	cout << d << endl;
	cout << ++d << endl;
	cout << d++ << endl;
	cout << d << endl;
}