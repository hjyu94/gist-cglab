#include "8_8 Calc.h"

// ������
Calc::Calc(int init_value)
	: m_value(init_value) {}

// ��� �޼ҵ�
void Calc::add(int value) { m_value += value; }
void Calc::sub(int value) { m_value -= value; }
void Calc::mult(int value) { m_value *= value; }
void Calc::print() {
	using namespace std;
	cout << m_value << endl;
}