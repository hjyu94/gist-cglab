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
	// �Ķ���ͷ� �Ѿ array�� �������̴�.
	// �׷��� �Ķ���ͷ� �迭�� �ѱ�� �ʹٸ� �迭 ������ ������ ���� �Ѱ���� �Ѵ�.
	cout << (int) score[0] << endl;
	cout << (int) score[1] << endl;
	cout << (int) score[2] << endl << endl;

}
int main() {
	int one_student_score; // 1 variable;
	int student_scores[5]; // 5 int

	one_student_score = 100;
	student_scores[0] = 100; // 1��° element�� index�� 0�̴�
	student_scores[1] = 90;


	// ����ü�� ���� �迭
	cout << sizeof(one_student_score) << endl;
	cout << sizeof(student_scores) << endl << endl;

	Rectangle rect_arr[10];
	cout << sizeof(Rectangle) << endl;
	cout << sizeof(rect_arr) << endl << endl;


	// array �ʱ�ȭ
	int my_arr[5] = { 1, 2, 3, 4, 5 };
	int my2_arr[] = { 1, 2, 3, 4, 5 };

	int math[NUM_STUDENTS] = { 1,2,3 };
	cout << my_arr[JACKJACK] << endl;
	cout << my_arr[DASH] << endl;
	cout << my_arr[VIOLET] << endl << endl;


	/*
	int num_students = 0;
	cin >> num_students; // ��Ÿ�ӽÿ� ������ ���� ����.
	int students_scores[num_students]; // error: �迭�� ���̴� ������ �ÿ� ������ �־�� �Ѵ�.
	// ���� �̸� �ذ��Ϸ��� #define NUM_STUDENTS 100000�� ���ų�(C, C++������ ����õ), �����Ҵ� ���
	*/

	cout << (int)&my_arr << endl;
	cout << "Size in main " << sizeof(my_arr) << endl;
	cout << (int)my_arr[0] << endl;
	cout << (int)my_arr[1] << endl;
	cout << (int)my_arr[2] << endl << endl;


	doSomething(my_arr);

	return 0;
}