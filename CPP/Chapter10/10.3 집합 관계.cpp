// AGGREGATION ���հ���
// lec has-a student
// lec has-a teacher

// ��ü: lec 
// ����: student, teacher

// �ٸ� Ŭ�������� ���� �� �ִ°�?
// std1�� lec1, lec2�� ���� �� �ִ�

// ����� ���縦 Ŭ������ �����Ѵ�.
// lec1�� ��������� std1�� ������� �ʴ´�.

// ���⼺: �ܹ���
// lec1 �������� std1, teacher1 �� ��� ����, �Լ��� ��� ����������
// std1�̳� teacher1������ lec�� ��� ����, �Լ��� ����� �� ����.

#include <iostream>
#include "10.3 Lecture.h"
#include "10.3 Student.h"
#include "10.3 Teacher.h"

int main() {
	using namespace std;

	/*
	// Composition Relationship
	// JJ�� �ּҰ� lec1, 2 ���� �ٸ���
	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(Teacher("Prof. Hong"));
	lec1.registerStudent(Student("JJ", 0));
	lec1.registerStudent(Student("Dash", 1));

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(Teacher("Prof. Good"));
	lec2.registerStudent(Student("JJ", 0));


	/******************************************************/

	Lecture lec1("Introduction to Computer Programming");
	Lecture lec2("Computational Thinking");

	Student std1("JJ", 0);
	Student std2("Dash", 1);
	
	Teacher teacher1("P. H");
	Teacher teacher2("P. G");

	lec1.assignTeacher(&teacher1);
	lec1.registerStudent(&std1);
	lec1.registerStudent(&std2);

	lec2.assignTeacher(&teacher2);
	lec2.registerStudent(&std1);

	cout << lec1 << endl;

	lec1.study();
	cout << endl;

	cout << lec2 << endl;

	// �����Լ� ���� ����������� std, teacher ���� �����ߴµ�
	// �����Լ��� ������ ������� �� ���̴�.
	// �׷��� �����Լ��� �ƴ϶� �ٸ� �Լ��ų�
	// std1, 2, 3�� �ٸ������� �� ����ϴ� ���
	// �����Ҵ����� �ν��Ͻ��� ����⵵ �Ѵ�.
	Student* ptr_std = new Student("JJ", 0);
	Lecture lec_test("lecture");
	lec_test.registerStudent(ptr_std); // �̹� �������̹Ƿ� & �ʿ� ����
	delete ptr_std; // delete memory (if necessary)

}