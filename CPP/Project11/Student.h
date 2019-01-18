#pragma once

#include "Person.h"

class Student : public Person
{
private:
	int m_intel;

public:
	// m_name은 Person의 멤버 변수
	// 멤버 변수의 관리는 Person한테 있다.
	
	// 생성자 호출 순서를 생각해보면
	// Student가 호출되는 상황에서는
	// m_name이 아직 정의되어있지 않아서
	// 에러가 나는 것.

	// 해당 생성자는 Person 클래스 내에서 정의해야 한다
	
	// Student에서 Person의 생성자를 호출해서
	// 간접적으로 호출하는 식.
	// m_name의 생성자가 Person에 있어야 한다!

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