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


// #include <iostream> // Monster.h���� �̹� include
#include "Monster.h"
using namespace std;

int main()
{
	// # Composition
	// m_location�� Monster�� ���� �ִ�
	// ���͸��� m_location�� �ٸ���
	// �̶� location�� monster�� �κ��̴� ��� �����Ѵ�.
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