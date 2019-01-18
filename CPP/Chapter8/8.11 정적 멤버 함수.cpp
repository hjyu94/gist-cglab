#include <iostream>
using namespace std;

class Something
{
public:
	class _init {
	public:
		_init() {
			s_value = 1234;
		}
	};

/*public->*/ private:
	static int s_value;
	int m_value;

	static _init s_initializer;

public:
	Something()
		: m_value(123), s_value(1024)
	{}

	static int getValue() 
	{
		return s_value;
		// return this->s_value;
		// return m_value;
		// static �Լ����� this �����͸� ����� �� ����.
	}

	int temp() {
		return this->s_value;
	}
};

int Something::s_value = 1024;
Something::_init Something::s_initializer; // �ν��Ͻ� ����

int main() 
{
	cout << Something::getValue() << endl;
	
	Something s1;
	cout << s1.getValue() << endl;
	// cout << s1.s_value << endl;

	// �Լ� ������
	// ��� �Լ��� ������
	
	// int (Something::*fptr1)() = &(s1.temp);
	// ��� ������ s1�� ���� �ֵ�.
	// s1, s2�� m_value�� �ּҰ� �ٸ���
	// �׷��� �Լ��� �ּҰ� ����
	// �� �ν��Ͻ����� �Լ��� ������ִ°� �ƴ϶�
	// ��� ��ġ�� Something Ŭ������ temp �Լ� �ϳ��� �����.
	// s1.temp()�� �����Ҷ� s1�� �ּҸ�(this) �Ѱܼ� �����ϴ� ��

	int (Something::*fptr1)() = &Something::temp;
	cout << (s2.*fptr1)() << endl;
	// non static function�� �ν��Ͻ��� ���ӵ� �����̹Ƿ�
	// this pointer�� �Ѱ��ֱ� ���� s2.*fptr1 �� ����
	// �Լ� ������ �տ� �ش� �ν��Ͻ��� ���־�� �Ѵ�.
	// this pointer�� �Ѱ���߸� �ϹǷ�

	// �׷��� static �Լ��� �ش� �ν��Ͻ��� ���Ӽ��� �����Ƿ�
	// Something:: �� ���� �����ؾ� �Ѵ�.
	int ( /*Something::*/ *fptr2)() = &Something::getValue;

}

// 1
s_value�� public�̾��ٰ� private���� �ٲ��
s1.s_value�� Something::s_value�δ� ������ �Ұ����ϴ�.
�ν��Ͻ� s1�� �ִٸ� s1.getValue()�� �����ϸ� ������
�ν��Ͻ��� ������ ���� ���¿����� ���� ��� ������ �����ϱ� ���ؼ�
getValue()�� static���� �ٲٸ� �ȴ�.

cout << Something::s_value << endl; ��ſ�
cout << Something::getValue() << endl; �� �������.


// 2
this�� �����ؾ� �ϴ� ������ �ȵȴ�.

static int getValue()
{
	return s_value;
	// return this->s_value;
	// return m_value;
	// static �Լ����� this �����͸� ����� �� ����.
}

// 3 
�Լ� �����Ϳ����� ���
int( /*Something::*/ *fptr2)() = &Something::getValue;

static �Լ��� this pointer�� �ʿ� ���� �����̴�.


// 4
static ��� ������ �����ڿ��� �ʱ�ȭ������ �� ����.
�����ڰ� static �Լ����� static ��� ������ ���� �� �� �ִ�.
-> inner Class�� ���� ���� �����ڿ��� ���� �ִ� ����� �ִ�.