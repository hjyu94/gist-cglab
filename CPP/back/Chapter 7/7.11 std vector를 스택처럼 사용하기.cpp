// 동적 할당 메모리를 직접 사용하는 것보다
// vector 를 쓰는 것이 훨씬 쉽다.

// 단 주의할 점은,
// 내부적으로 사용되는 new와 delete이 적게 사용되는 방향으로 만드는 것이 효율적

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// int *v_ptr = new int[3]{1,2,3}; 과 비슷한 상황	
	std::vector<int> v{ 1,2,3 };

	// size, capacity 개념!
	// 전체 capacity 중 내가 사용할 양을 size라고 생각하면 된다
	
	v.resize(2);
	for (unsigned int i = 0; i<v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	// 1,2,3 중 1,2만 출력된다

	cout << "size:" << v.size() << ", capacity: " << v.capacity() << endl;
	
	// 그러면 v[2]는 사라진것일까?
	
	// cout << v[2] << endl;
	// cout << v.at(2) << endl;
	// 런타임 에러 !! 

	int *ptr = v.data();
	cout << ptr[2] << endl;
	// 이렇게 출력하면 v[2]가 나온다.

	// 이 말은 즉,
	// 더 작은 값으로 resize할 때 (v.resize(2))
	// 새로운 메모리를 할당한 뒤 원래 데이터 3개 중 2개를 복사하여
	// 새로운 메모리에 저장하고 원래 메모리를 반납하는 것이 아니라
	// 속도 향상을 위해 new, delete 방식이 아니라 그냥 값이없는 셈치고 사용할 수 있게 하려했던 것.

	cout << endl << endl;
	

	// size와 capacity 값을 늘리는 경우 어떤 일이 생기나?

	cout << "size 10으로 변경" << endl;
	v.resize(10);
	for (auto &e : v)
		cout << e << " ";
	cout << endl << endl;

	cout << "v 다시 초기화" << endl;
	v = std::vector<int>{ 1,2,3 };
	cout << "capacity 1024으로 변경" << endl;
	
	// reverse는 메모리의 용량을 미리 확보해 놓겠다는 의미
	v.reserve(1024);
	
	for (auto &e : v)
		cout << e << " ";
	cout << endl << endl;
	// 왜 reverse를 사용해서 충분히 capacity를 확보해 두는 경우가 있냐면
	// 뒤에 원소가 추가될 때 메모리를 받아오는 작업이 불필요해서
	// 최대한 new, delete를 줄이는 방향으로 사용하는 것.
}
