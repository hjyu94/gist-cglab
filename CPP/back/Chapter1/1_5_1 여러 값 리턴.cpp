#include <iostream>
#include <tuple> // 여러개의 데이터를 쌍으로 표시

using namespace std;

// 1
// tuple<int, int> my_func() {
//	 return tuple<int, int>(1, 2);
// }

auto my_func() {
	return tuple(1, 2);
}


int main() {

	

	// 1) tuple<int, int> result = my_func();
	auto result = my_func();

	auto[a, b] = my_func();
	cout << a << " " << b << endl;
	
	
	cout << get<0>(result) << " " << get<1>(result) << endl;

	return 0;
}