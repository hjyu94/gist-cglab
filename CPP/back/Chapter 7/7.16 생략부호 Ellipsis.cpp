// 매개변수를 자유롭게 넣어주고 싶다.

#include <iostream>
#include <cstdarg> // for ellipsis
using namespace std;

double findAverage(int count, ...) {
	double sum = 0;

	va_list list;
	// char *
	
	va_start(list, count);
	// count: argument의 개수
	
	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int);
	// type:int 로 변환

	va_end(list);

	return sum / count;
}

int main() {
	cout << findAverage(1, 1, 2, 3, "Hello world", 'c') << endl; // 2부터 무시됨
	cout << findAverage(3,1,2,3) << endl;
	cout << findAverage(5,1,2,3,4,5) << endl;
	cout << findAverage(10,1,2,3,4,5) << endl;
	// 10개의 파라매터라고 했는데, 덜 들어가서 이상한 숫자를 출력

	return 0;
}