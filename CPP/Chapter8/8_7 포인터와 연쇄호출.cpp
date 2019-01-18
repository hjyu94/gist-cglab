#include <iostream>
using namespace std;

class Simple {
private:
	int m_id;
public:
	Simple(int id) {
		setID(id);
		// this->setID(id);
		// (*this).setID(id);

		cout << "constructor: " << this << endl;
	}
	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};

// Chaining
class Calc {
private:
	int m_value;
public:
	Calc(int init_value)
		: m_value(init_value) {}

	//void add(int value) { m_value += value; }
	//void sub(int value) { m_value -= value; }
	//void mult(int value) { m_value *= value; }
	//void print() {
	//	cout << m_value << endl;
	//}

	Calc& add(int value) { m_value += value; return *this; }
	// Calc&: Calc Ÿ���� ���۷���
	Calc& sub(int value) { m_value -= value; return *this; }
	Calc& mult(int value) { m_value *= value; return *this; }
	void print() {
		cout << m_value << endl;
	}
};

int main() {
	Simple s1(1), s2(2);
	s1.setID(2);
	s2.setID(4);

	cout << "main : " << &s1 << endl;
	cout << "main : " << &s2 << endl;

	// Simple::setID(&s2, 4); == s2.setID(4);
	// �����, ���������� �̷��� �����Ѵ�
	// this ��� �Ķ���Ͱ� �����Ǿ� �ִ� ��

	cout << endl;

	// ���� ȣ��
	Calc cal(10);
	
	/*
	Calc cal(10);
	cal.add(100);
	cal.sub(50);
	cal.mult(2);
	cal.print();
	*/
	
	cal.add(100).sub(50).mult(2).print();

	//Calc &temp1 = cal.add(10);
	//Calc &temp2 = temp1.sub(50);
	//Calc &temp3 = temp2.mult(2);
	//temp3.print();

	return 0;
}