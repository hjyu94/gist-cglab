#include <iostream>

using namespace std;

struct Rectangle {
	int length, width;
};

enum StudentName {
	JACKJACK, // =0
	DASH, // =1
	VIOLET, // =2
	NUM_STUDENTS, // =3
};

void doSomething(int score[]) {

	cout << (int) &score << endl;
	cout << "Size in doSomething " << sizeof(score) << endl; 
	// 파라매터로 넘어간 array는 포인터이다.
	// 그래서 파라매터로 배열을 넘기고 싶다면 배열 원소의 개수도 같이 넘겨줘야 한다.
	cout << (int) score[0] << endl;
	cout << (int) score[1] << endl;
	cout << (int) score[2] << endl << endl;

}
int main() {
	int one_student_score; // 1 variable;
	int student_scores[5]; // 5 int

	one_student_score = 100;
	student_scores[0] = 100; // 1번째 element의 index는 0이다
	student_scores[1] = 90;


	// 구조체를 담은 배열
	cout << sizeof(one_student_score) << endl;
	cout << sizeof(student_scores) << endl << endl;

	Rectangle rect_arr[10];
	cout << sizeof(Rectangle) << endl;
	cout << sizeof(rect_arr) << endl << endl;


	// array 초기화
	int my_arr[5] = { 1, 2, 3, 4, 5 };
	int my2_arr[] = { 1, 2, 3, 4, 5 };

	int math[NUM_STUDENTS] = { 1,2,3 };
	cout << my_arr[JACKJACK] << endl;
	cout << my_arr[DASH] << endl;
	cout << my_arr[VIOLET] << endl << endl;


	/*
	int num_students = 0;
	cin >> num_students; // 런타임시에 변수에 값이 들어간다.
	int students_scores[num_students]; // error: 배열의 길이는 컴파일 시에 결정돼 있어야 한다.
	// 보통 이를 해결하려면 #define NUM_STUDENTS 100000를 쓰거나(C, C++에서는 비추천), 동적할당 사용
	*/

	cout << (int)&my_arr << endl;
	cout << "Size in main " << sizeof(my_arr) << endl;
	cout << (int)my_arr[0] << endl;
	cout << (int)my_arr[1] << endl;
	cout << (int)my_arr[2] << endl << endl;


	doSomething(my_arr);

	return 0;
}