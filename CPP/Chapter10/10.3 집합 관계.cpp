// AGGREGATION 집합관계
// lec has-a student
// lec has-a teacher

// 전체: lec 
// 부픔: student, teacher

// 다른 클래스에도 속할 수 있는가?
// std1이 lec1, lec2에 속할 수 있다

// 멤버의 존재를 클래스가 관리한다.
// lec1이 사라지더라도 std1이 사라지지 않는다.

// 방향성: 단방향
// lec1 내에서는 std1, teacher1 의 멤버 변수, 함수를 사용 가능하지만
// std1이나 teacher1에서는 lec의 멤버 변수, 함수를 사용할 수 없다.

#include <iostream>
#include "10.3 Lecture.h"
#include "10.3 Student.h"
#include "10.3 Teacher.h"

int main() {
	using namespace std;

	/*
	// Composition Relationship
	// JJ의 주소가 lec1, 2 에서 다르다
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

	// 메인함수 내의 지역변수들로 std, teacher 들을 생성했는데
	// 메인함수가 끝날때 사라지게 될 것이다.
	// 그런데 메인함수가 아니라 다른 함수거나
	// std1, 2, 3를 다른곳에서 또 써야하는 경우
	// 동적할당으로 인스턴스를 만들기도 한다.
	Student* ptr_std = new Student("JJ", 0);
	Lecture lec_test("lecture");
	lec_test.registerStudent(ptr_std); // 이미 포인터이므로 & 필요 없음
	delete ptr_std; // delete memory (if necessary)

}