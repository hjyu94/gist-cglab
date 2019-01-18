#include <iostream>
using namespace std;

class B {
private:
	int m_b;
public:
	B(const int& m_b_in)
		: m_b(m_b_in) 
	{

	}
};

class Something {
private:
	int m_i = 1;
	double m_d = 1.0;
	char m_c = 'a';
	int m_arr[5] = { 1,2,3,4,5 };
	B m_b{ 1 };

public:
	Something() 
		// initializer list
		: m_i(1), m_d(3.14), m_c('a'), m_arr{ 1,2,3,4,5 }, m_b(m_i-1)
		// m_i{1}, m_d{3.14}
		// �̷��� curly bracket�� �ᵵ �����ϳ�
		// ����ȯ�� �ڵ����� ������ �ʴ´ٴ� ������ �ִ�. (�� �� �����ϴ�)
	{
		/*m_i = 1;
		m_d = 3.14;
		m_c = 'a';*/
	}

	void print() {
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr) cout << e << " ";
		cout << endl;
	}
};

int main() {
	Something som;
	som.print();
}