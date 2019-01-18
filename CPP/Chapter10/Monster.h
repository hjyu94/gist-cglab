#pragma once

#include <string>
#include "Position2D.h"

class Monster
{
private:
	std::string m_name;
	
	/*
		int m_x; // location
		int m_y;
		-> 대신에 Position2D 멤버 변수로 추가
	*/

	Position2D m_location;
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

public:
	Monster(const std::string name_in, const Position2D& pos_in)
		: m_name(name_in), m_location(pos_in) {}

	void moveTo(const Position2D& pos_target)
	{
		m_location.set(pos_target);
	}

	friend std::ostream& operator << (std::ostream& out, const Monster& monster)
	{
		// out << monster.m_name << " " << monster.m_x << " " << monster.m_y << std::endl;
		out << monster.m_name << " " << monster.m_location;
		return out; // for chaining
	}
};