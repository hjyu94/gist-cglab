#include <iostream>
#include <array>

using namespace std;

int main() {
	//int array[5] = { 1,2,3,4,5 };
	array<int, 5> my_arr = { 1,2,3,4,5 };
	my_arr = { 1,2, }; // 개수가 모자르면 0으로 채워준다

	cout << my_arr[10] << endl; // 맞는지 안맞는지 상관없이 그냥 실행시켜버린다
	cout << my_arr.at(10) << endl; // 예외처리를 한다-> 퍼포먼스가 느려질수도 있다는 단점은 있다.
}