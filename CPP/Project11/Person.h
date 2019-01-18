#pragma once

#include <iostream>
#include <string>

class Person
{
private:
	std::string m_name;

public:
	Person() {}

	// Person�� �ڽ� Ŭ�������� m_name�� ����� ���� ������
	// �������� ���� å���� Person Ŭ�������� �ִ�.
	Person(const std::string & name_in)
		: m_name(name_in)
	{}

	void setName(const std::string & name_in)
	{
		m_name = name_in;
	}

	std::string getName() const
		// const ��� �Լ� : ���ο��� ��� ������ ���� �ٲ��� �ʴ´�.
	{
		return m_name;
	}
	
	void doNothing() const
	{
		using namespace std;
		// ���� �ȿ� ��� Person.h�� ����ϴ� ��� ���Ͽ���
		// using namespace std;�� ����Ǵ� ���� ���� �� �ִ�.
		cout << m_name << " is doing nothing " << endl;
	}
};