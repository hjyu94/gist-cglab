#pragma once // �������
#include <iostream>

// ������Ͽ� ���� �� ��Ƴ����� ���� ����ϴ�.

class Calc {
private:
	int m_value;
public:
	Calc(int init_value);

	void add(int value);
	void sub(int value);
	void mult(int value);
	void print();
};
