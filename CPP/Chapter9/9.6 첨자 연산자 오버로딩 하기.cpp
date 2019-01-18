/*
	std::array, std::vector��
	�Լ��� ȣ���ϴ� ��ſ�
	[] �����ڸ� ����� ���� �����ϰų� �ٲ۴�
	[] �������� �����ε�
*/

#include <iostream>
using namespace std;

class IntList
{
private:
	int m_list[10];
	// 10���� �޸� ������ �׻� Ȯ���Ǿ��ִ�
	
	// �׷��� std::vector�� ���� �޸� �Ҵ��� ����� ����
	// �����Ϸ��� �ϴ� �޸𸮰� ����� �����ִ��� allocation ���ִ���
	// Ȯ���غ��� �Ѵ�.

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int * getList()
	{
		return m_list;
	}
};

int main()
{
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(2) << endl;
	
	my_list.getList()[2] = 10;
	// ptr + 1 = ptr + sizeof(*ptr) = ptr[1]
	cout << my_list.getList()[3] << endl;
}