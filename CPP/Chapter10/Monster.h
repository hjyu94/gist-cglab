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
		-> ��ſ� Position2D ��� ������ �߰�
	*/

	Position2D m_location;
	// ���� Ŭ������ ���� Ŭ����

	// COMPOSITION
	// position is part-of monster

	// ���� ��ü / ��ġ ����
	
	// m_location�� ������ ���� �ν��Ͻ����� �����ִ� ����
	// �ٸ� Ŭ�������� ������ �ʴ´�
	// [�򰥸����� ��] Position2D ��ü�� ��Ȱ�� ����
	// Knight ���� Ŭ������ ���ܼ� �³װ� Position2D�� ������
	// �� m_location�� Knight���� ��
	
	// ����� ���縦 Ŭ������ �����Ѵ�.
	// mon1�� ������� m_location�� ���� �������.

	// ���⼺: �ܹ���
	// ���� Ŭ���� �������� Position2D���� get, set ���� �Լ��� �ִٴ°��� �˰� �۾�
	// Position2D������ ���� Ŭ������ � �Լ��� �ִ����� �� �ʿ䰡 ����

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