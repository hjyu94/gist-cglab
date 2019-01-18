#pragma once

#include <iostream>
#include <string>

class Student
{
private:
	std::string m_name;
	int m_intel;

public:
	Student(const std::string &name_in, const int &intel_in)
		: m_name(name_in), m_intel(intel_in) 
	{}
	
	std::string getName()
	{
		return m_name;
	}

	void setIntel(const int& intel_input)
	{
		m_intel = intel_input;
	}
	
	int getIntel()
	{
		return m_intel;
	}
};