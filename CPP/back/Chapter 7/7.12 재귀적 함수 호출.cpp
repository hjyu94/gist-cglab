// 재귀적 용법을 사용할 땐 언제 끝나는지를 신경써야 한다

// recursion 을 잘못 사용하면
// 스택 오버플로우가 발생할 수 있다

// 스택 오버플로우가 너무 무섭다면
// std::vector를 스택으로 사용하는 대처방안도 있다

// recursion 이 iterative보다 구현하기 쉽다
// 하지만 recursion 은 스택을 사용하기 때문에
// 가능하면 iteration으로 바꿔서 사용하는 것이 좋다.
// 성능이 중요하다면 iteration을 사용하는 것을 추천한다

#include <iostream>
using namespace std;

void countDown(int count) {
	cout << count << endl;
	if(count>0)
		countDown(count - 1);
}

int main() {
	countDown(5);
	return 0;
}