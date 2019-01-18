#include <iostream>
using namespace std;

class Something
{
public:
	// static int m_value = 1;
	// static 멤버 변수는 initialize를 할 수 없다

	static int s_value;

	static const int s_v = 1;
	// static const 멤버 변수는 선언과 동시에 값을 초기화해줘야 한다.

	static constexpr int s_vv = 1;
	// static const는 런타임에 값이 들어갈 수도 있는데
	// constexpr은 무조건 값이 정해져야 한다.
	// 디자인패턴 중 싱글턴에서 이 표현을 사용한다.
};

int Something::s_value = 1;
// 헤더파일을 따로 관리하는 경우
// cpp 파일에 정의해야 컴파일 에러가 생기지 않는다.
// static은 cpp로 빼야한다.

int main() {
	// 인스턴스가 없을 때도 같은 주소가 나온다
	cout << &Something::s_value << " " << Something::s_value << endl;

	Something st1;
	Something st2;

	st2.s_value = 2;

	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
	// 둘의 주소가 같다

	Something::s_value = 1024;
	cout << &Something::s_value << " " << Something::s_value << endl;

	return 0;
}