// 방어적 프로그래밍
// 사용자가 어떻게 사용하던지 작동이 될 수 있도록

// syntax error 문법 오류
// ; 등을 빼먹었을 때
// 컴파일러가 잡아 준다

// semantic error 문맥 오류
// int x;
// cin >> x;
// if(x>=5) cout<<"greater than 5" ;
// 논리 오류, x가 5일때도 출력됨.

// violated assumption
// 사용자가 전혀 다른 의도로 프로그램을 사용하는 경우

#include <iostream>
#include <string>
using namespace std;

int main() {
	string hello = "Hello, my name is Jack jack";
	
	int ix;

	// violated assumption
	// 안전장치, 방어장치를 걸어두는 습관을 들이자
	while (true) {
		cin >> ix;
		cout << hello[ix] << endl;

		if (ix >= 0 && ix <= hello.size() - 1) {
			cout << hello[ix] << endl;
			break;
		}
		else
			cout << "Please try again" << endl;
	}

	return 0;
}
