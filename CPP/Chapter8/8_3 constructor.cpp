#include <iostream>
using namespace std;

class Fraction {
public:
	int m_numerator;
	int m_denominator;

public:
	// �����ڰ� �ƹ��͵� ���� ��
	// Fraction() {} 
	// default constructor : construction �ɶ� �ڵ����� ȣ��Ǵ� �Լ�

	Fraction(const int& numerator_input=1, const int& denominatro_input=1) {
		cout << "constructor start" << endl;
		m_numerator = numerator_input;
		m_denominator = denominatro_input;
		cout << "constructor finished" << endl;
	}

	void print() {
		cout << m_numerator << " / " << m_denominator << endl;
	}
};


class Second {
public:
	Second() {
		cout << "Second constructor()" << endl;
	}
};

class First {
	Second sec;

public:
	First() {
		cout << "First constructor()" << endl;
	}
};

int main() {
	// �����ڰ� �ν��Ͻ��� ����� ���� �ƴ�
	// �̸��� ���ӽ� ������ �򰥸��� �ȵ�
	// construction �ɶ� �ڵ����� ȣ��Ǵ� �Լ�

	Fraction frac(1,3);
	// ��� ������ ������� 1, 3�� �־��ش�
	frac.print();

	// �Ķ���Ͱ� ���� ��쿡�� frac() �̷��� ���� �ȵǰ� frac ���� ����
	// �����ڸ� �ϳ��� ������ָ� �⺻ �����ڸ� ȣ������ �ʱ� �����̴�.
	// �̸� �ذ��Ϸ��� �⺻ �����ڸ� ����� �ָ� �ȴ�.
	Fraction frac2;
	frac2.print();
	
	cout << endl;

	// Ŭ���� ���� �ٸ� Ŭ���� Ÿ���� ��������� �߰��Ѵ�.
	// �� ��� ��� ���� -> ��� �Լ�
	// Second ������ ȣ�� -> First ������ ȣ�� �����̴�.
	First fir;

	return 0;
}