#pragma once

#include <vector>
#include "10.3 Student.h"
#include "10.3 Teacher.h"

class Lecture
{
private:
	std::string m_name;

	/*
	P1���� ������ �ڵ�
	Teacher teacher;
	std::vector<Student> students;
	*/

	// S1
	// �ּҸ� �޾ƿ��� �Ǹ� Lecture �ν��Ͻ���
	// ������ �� teacher, students ������ ���������
	// �� ���� �ȿ� �ִ� ���� (*teacher, *students[1], ...)��
	// �������� �ʴ´�.
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
	// �� �ڿ� ���� const�� ����??
	{
		teacher = teacher_input;
	}

	void registerStudent(Student * const student_input)
	{
		students.push_back(student_input);
		// P1)
		// �̶� &student_input��
		// push�� �� &students[0]�� �ٸ���
		// �̸� �ذ��Ϸ��� �ּҸ� �޾ƿ��� ������ �ڵ带 �ٲ۴�.
	}

	void study() // �ش� ������ ��� �л����� ������ +1 �ȴ�.
	{
		std::cout << m_name << " Study !!" << std::endl;

		for (auto & element : students) 
			// auto element ��� ���� �� ������ X
			// �ּҸ� ������ �;� �Ѵ�.
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