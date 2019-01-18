#include <iostream>
#include <vector>
#include <algorithm> // for shuffle

using namespace std;

class Cents {
private:
	int m_cents;
public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// friend��� �����ϸ� private ��� ������ ����� �� �־�����.
	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		if (c1.m_cents == c2.m_cents) return true;
		else false;
	}

	// sort �� ���� Cents �� ������ �����ε�
	// > �� �ƴ϶� < �� �����ε� �Ǿ�� �Ѵ�.
	friend bool operator < (const Cents &c1, const Cents &c2) {
		return c1.m_cents < c2.m_cents;
	}

	friend std::ostream& operator << (std::ostream &out, const Cents &cents) {
		out << cents.m_cents;
		return out; // chaining
	}

};

int main() {
	Cents cents1(5);
	Cents cents2(5);

	if (cents1 == cents2)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
	cout << endl;

	// 1~20 �� shuffle �� ����غ���.
	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
		arr[i].getCents() = i;
	
	std::random_shuffle(begin(arr), end(arr));

	for (auto &e : arr)
		cout << e << " ";
	cout << endl;

	// sorting
	std::sort(begin(arr), end(arr));

	for (auto &e : arr)
		cout << e << " ";
	cout << endl;

}