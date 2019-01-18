#include <iostream>
#include <array>

using namespace std;

void printLength(array<int, 5> my_arr) { 
	// 복사해서 넘어가기 때문에 속도가 느려질 수도 있다, 
	// 속도가 중요한 경우라면 값을 복사하지 않고 위치를 넘겨주는
	// 레퍼런스 포인터를 쓰는것이 좋다.
	cout << my_arr.size() << endl;
}

int main() {
	//int array[5] = { 1,2,3,4,5 };
	array<int, 5> my_arr = { 1,2,3,4,5 };
	my_arr = { 1,2, }; // 개수가 모자르면 0으로 채워준다
	
	//cout << my_arr[10] << endl; // 맞는지 안맞는지 상관없이 그냥 실행시켜버린다
	//cout << my_arr.at(10) << endl; // 예외처리를 한다-> 퍼포먼스가 느려질수도 있다는 단점은 있다.
	cout << my_arr.size() << endl; // sizeof(my_arr) / sizeof(int)
	printLength(my_arr);

	
	array<int, 5> my_arr2 = { 1,21,3,40,2 };
	
	cout << "소팅 전" << endl;
	for (auto &element : my_arr2) // 레퍼런스를 넘겨주면 속도가 빨라진다.
		cout << element << " ";
	cout << endl;

	std::sort(my_arr2.begin(), my_arr2.end());
	
	cout << "소팅 후" << endl;
	for (auto &element : my_arr2)
		cout << element << " ";
	cout << endl;

	my_arr2 = { 1,21,3,40,2 };
	std::sort(my_arr2.rbegin(), my_arr2.rend());

	cout << "r 소팅 후" << endl;
	for (auto &element : my_arr2)
		cout << element << " ";
	cout << endl;

	return 0;
}