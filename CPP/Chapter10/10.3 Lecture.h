#pragma once

#include <vector>
#include "10.3 Student.h"
#include "10.3 Teacher.h"

class Lecture
{
private:
	std::string m_name;

	/*
	P1에서 문제의 코드
	Teacher teacher;
	std::vector<Student> students;
	*/

	// S1
	// 주소를 받아오게 되면 Lecture 인스턴스가
	// 삭제될 때 teacher, students 변수는 사라지지만
	// 그 변수 안에 있는 내용 (*teacher, *students[1], ...)는
	// 지워지지 않는다.
	Teacher* teacher;
	std::vector<Student*> students;
	

public:
	Lecture(const std::string &name_in)
		: m_name(name_in)
	{}

	~Lecture()
	{
		// do NOT delete teacher
		// do NOT delete students
	}

	void assignTeacher(Teacher* const teacher_input)
	// 앞 뒤에 붙은 const의 차이??
	{
		teacher = teacher_input;
	}

	void registerStudent(Student * const student_input)
	{
		students.push_back(student_input);
		// P1)
		// 이때 &student_input와
		// push된 후 &students[0]가 다르다
		// 이를 해결하려면 주소를 받아오는 식으로 코드를 바꾼다.
	}

	void study() // 해당 수업을 듣는 학생들의 지능이 +1 된다.
	{
		std::cout << m_name << " Study !!" << std::endl;

		for (auto & element : students) 
			// auto element 라고 쓰면 값 변하지 X
			// 주소를 복사해 와야 한다.
			// element.setIntel(element.getIntel() + 1);
			element->setIntel(element->getIntel() + 1);

	}

	friend std::ostream& operator << (std::ostream& out, const Lecture &lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;

		out << lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << element->getName() << ", " << element->getIntel() << std::endl;

		return out;
	}

};