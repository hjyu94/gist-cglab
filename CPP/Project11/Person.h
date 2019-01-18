#pragma once

#include <iostream>
#include <string>

class Person
{
private:
	std::string m_name;

public:
	Person() {}

	// Person의 자식 클래스들이 m_name을 사용할 수는 있지만
	// 전적으로 관리 책임은 Person 클래스에게 있다.
	Person(const std::string & name_in)
		: m_name(name_in)
	{}

	void setName(const std::string & name_in)
	{
		m_name = name_in;
	}

	std::string getName() const
		// const 멤버 함수 : 내부에서 멤버 변수의 값을 바꾸지 않는다.
	{
		return m_name;
	}
	
	void doNothing() const
	{
		using namespace std;
		// 내부 안에 써야 Person.h를 사용하는 모든 파일에서
		// using namespace std;가 실행되는 것을 막을 수 있다.
		cout << m_name << " is doing nothing " << endl;
	}
};