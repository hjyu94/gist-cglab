#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 정적 배열
	// std::array<int, 5> array;

	// 동적 배열
	std::vector<int> array;

	std::vector<int> array2 = { 1,2,3,4,5 };
	cout << array2.size() << endl;

	std::vector<int> array3 = { 1,2,3, };
	cout << array3.size() << endl << endl;


	std::vector<int> array4 { 1,2,3, }; // uniform initialization
	cout << array4.size() << endl;
	for (auto &itr : array4)
		cout << itr << " ";
	cout << endl << endl;
	
	array4.resize(10);
	cout << "resize 이후" << endl;
	cout << array4.size() << endl;
	for (auto &itr : array4)
		cout << itr << " ";
	cout << endl << endl;

	// 편한점?
	int *my_arr = new int[5];
	delete[] my_arr;
	// 기존 동적할당은 다 쓴 뒤에는 지워야 한다
	// 그런데 vector의 경우 알아서 지워지기 때문에
	// 메모리가 새지 않는다.
	// 또한 size(), at(), start(), end(), resize(10) 등의 함수를 사용할 수 있다.

	return 0;
}