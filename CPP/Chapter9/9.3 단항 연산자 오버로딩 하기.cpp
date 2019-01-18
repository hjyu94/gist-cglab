#include <iostream>
using namespace std;

class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// ���� ������ �����ε�
	Cents operator - () const
	{
		return Cents(-m_cents);
	}
	/*
		Cents operator - (Cents* this){ return Cents(-(this->m_cents)); }
	*/

	bool operator ! () const
	{
		// Cents(0) �̸� ���� ���� -> false ����
		// !Cents(0) -> true ����
		return (m_cents == 0) ? true : false;
	}

	friend std::ostream& operator << (std::ostream &out, const Cents &cents) {
		out << cents.m_cents;
		return out; // chaining
	}

};

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	cout << cents1 << endl;
	cout << -cents1 << endl;

	auto temp = !cents1; // data type : bool
		
}