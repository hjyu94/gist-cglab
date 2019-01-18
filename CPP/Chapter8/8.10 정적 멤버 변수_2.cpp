#include <iostream>
using namespace std;

class Something
{
public:
	// static int m_value = 1;
	// static ��� ������ initialize�� �� �� ����

	static int s_value;

	static const int s_v = 1;
	// static const ��� ������ ����� ���ÿ� ���� �ʱ�ȭ����� �Ѵ�.

	static constexpr int s_vv = 1;
	// static const�� ��Ÿ�ӿ� ���� �� ���� �ִµ�
	// constexpr�� ������ ���� �������� �Ѵ�.
	// ���������� �� �̱��Ͽ��� �� ǥ���� ����Ѵ�.
};

int Something::s_value = 1;
// ��������� ���� �����ϴ� ���
// cpp ���Ͽ� �����ؾ� ������ ������ ������ �ʴ´�.
// static�� cpp�� �����Ѵ�.

int main() {
	// �ν��Ͻ��� ���� ���� ���� �ּҰ� ���´�
	cout << &Something::s_value << " " << Something::s_value << endl;

	Something st1;
	Something st2;

	st2.s_value = 2;

	cout << &st1.s_value << " " << st1.s_value << endl;
	cout << &st2.s_value << " " << st2.s_value << endl;
	// ���� �ּҰ� ����

	Something::s_value = 1024;
	cout << &Something::s_value << " " << Something::s_value << endl;

	return 0;
}