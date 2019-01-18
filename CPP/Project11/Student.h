#pragma once

#include "Person.h"

class Student : public Person
{
private:
	int m_intel;

public:
	// m_name�� Person�� ��� ����
	// ��� ������ ������ Person���� �ִ�.
	
	// ������ ȣ�� ������ �����غ���
	// Student�� ȣ��Ǵ� ��Ȳ������
	// m_name�� ���� ���ǵǾ����� �ʾƼ�
	// ������ ���� ��.

	// �ش� �����ڴ� Person Ŭ���� ������ �����ؾ� �Ѵ�
	
	// Student���� Person�� �����ڸ� ȣ���ؼ�
	// ���������� ȣ���ϴ� ��.
	// m_name�� �����ڰ� Person�� �־�� �Ѵ�!

	Student(const std::string &name_in="No name", const int &intel_in = 0)
		//: m_name(name_in), m_intel(intel_in)
		: Person(name_in), m_intel(intel_in)
	{}

	void setIntel(const int& intel_input)
	{
		m_intel = intel_input;
	}

	int getIntel()
	{
		return m_intel;
	}

	void study()
	{
		std::cout << getName() << "is studying" << std::endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Student & student)
	{
		out << student.getName();
		return out;
	}
};