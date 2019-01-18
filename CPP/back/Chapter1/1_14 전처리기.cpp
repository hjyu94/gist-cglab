#include <iostream>
using namespace std;

// 전처리기. 빌드 시작 전에 실행된다.
// 효력 범위는 해당 파일이다
// 다른 파일의 define은 읽지 못한다.
#define MY_NUMBER 9
#define MAX(a,b) ((a>b) ? (a): (b))

#define LIKE_APPLE

int main() {
	cout << MY_NUMBER << endl;
	cout << MAX(1+2, 4) << endl;


#ifdef LIKE_APPLE
	cout << "You already liked apple" << endl;
#endif

#ifndef LIKE_APPLE
	cout << "You didn't like apple" << endl;
#endif


#ifdef LIKE_APPLE
	cout << "You already liked apple" << endl;
#else
	cout << "You didn't liked apple" << endl;
#endif



	return 0;
}