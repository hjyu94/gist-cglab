#include <iostream>
using namespace std;

class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	operator int()
	{
		cout << "cast here(in Cents)" << endl;
		return m_cents;
	}
	// int() 형변환을 오버로딩
};

class Dollar
{
private:
	int m_dollars;

public:
	Dollar(const int & input) : m_dollars(input) {}
	operator Cents()
	{
		cout << "cast here(in Dollar)" << endl;
		return Cents(m_dollars * 100);
	}
};

void printInt(const int &value)
{
	cout << value << endl;
}

int main()
{
	Cents cents(7);

	// Cast here 4번 호출
	int value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);
	printInt(cents);

	cout << endl;

	Dollar dol(2);
	Cents cents_2 = dol; // cast here
	printInt(cents); // cast here

	return 0;
}