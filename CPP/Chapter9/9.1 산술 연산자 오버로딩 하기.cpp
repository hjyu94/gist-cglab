#include <iostream>
using namespace std;

class Cents {
private:
	int m_cents;
public:
	// Cents() {}; // �⺻ ������
	Cents(int cents=0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	// friend �Լ��� �����ε� �ϴ� ���
	friend Cents operator + (const Cents &c1, const Cents &c2)
	{
	return Cents(c1.getCents() + c2.m_cents);
	}
	// c1.getCents()�� �޾ƿ��°� �������� friend �� �̿��ϸ� �ȴ�.
	

	// ��� �Լ��� �����ε� �ϴ� ���
	// =, [1,2,3,...], (1,2,3,...), -> ��
	// �̷� �÷θ� �����ϴ�.
	Cents operator + (const Cents &c2)
	{
		return Cents(this->m_cents + c2.m_cents);
	}
};

/**********************************************************/
// ������ �����ε� �ϱ� ���� �ϴ� ���

void add(const Cents &c1, const Cents &c2, Cents &c_out) {
	c_out.getCents() = c1.getCents() + c2.getCents();
}

Cents add(const Cents &c1, const Cents &c2) {
	return Cents(c1.getCents() + c2.getCents());
}

/**********************************************************/
// ������ �����ε�: �Ϲ� �Լ��� �ϴ� ���

Cents /*add*/ operator + (const Cents &c1, const Cents &c2) {
	return Cents(c1.getCents() + c2.getCents());
}

/**********************************************************/

int main() {
	Cents cents1(6);
	Cents cents2(8);

	// �⺻�����ڰ� ���� �����ڸ� �����ε��ϸ� ����
	// �Ķ���Ϳ� �⺻���� �־��ִ� ����� �ִ�.
	Cents sum;

	add(cents1, cents2, sum);
	cout << sum.getCents() << endl;

	cout << add(cents1, cents2).getCents() << endl;
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;
}