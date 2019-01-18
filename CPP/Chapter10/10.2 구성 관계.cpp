// 몬스터 클래스의 내부 클래스

// COMPOSITION
// position is part-of monster

// 몬스터 전체 / 위치 부픔

// m_location은 각각의 몬스터 인스턴스에만 속해있는 거지
// 다른 클래스에는 속하지 않는다
// [헷갈릴만한 것] Position2D 자체는 재활용 가능
// Knight 등의 클래스가 생겨서 걔네가 Position2D를 쓰더라도
// 그 m_location은 Knight만의 값

// 멤버의 존재를 클래스가 관리한다.
// mon1가 사라지면 m_location도 같이 사라진다.

// 방향성: 단방향
// 몬스터 클래스 내에서는 Position2D에서 get, set 등의 함수가 있다는것을 알고 작업
// Position2D에서는 몬스터 클래스에 어떤 함수가 있는지는 알 필요가 없다


// #include <iostream> // Monster.h에서 이미 include
#include "Monster.h"
using namespace std;

int main()
{
	// # Composition
	// m_location이 Monster에 속해 있다
	// 몬스터마다 m_location이 다르다
	// 이때 location이 monster의 부분이다 라고 설명한다.
	Monster mon1("Sanson", Position2D(0, 0));
	// mon1.m_location;
	cout << mon1 << endl;

	Monster mon2("Parsival", Position2D(0, 0));
	// mon1.m_location;
	cout << mon2 << endl;

	// while (1) // game loop
	{
		// event
		mon1.moveTo(Position2D(1,1));
		cout << mon1 << std::endl;
	}

	return 0;
}