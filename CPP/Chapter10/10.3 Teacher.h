#pragma once

#include <iostream>
#include <string>

class Teacher
{
private:
	std::string m_name;

public:
	Teacher(const std::string& name_in="No Name")
		: m_name(name_in) 
	{}

	
};