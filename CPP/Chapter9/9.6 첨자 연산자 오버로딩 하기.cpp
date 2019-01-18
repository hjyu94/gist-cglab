/*
	std::array, std::vector는
	함수를 호출하는 대신에
	[] 연산자를 사용해 값을 접근하거나 바꾼다
	[] 연산자의 오버로딩
*/

#include <iostream>
using namespace std;

class IntList
{
private:
	int m_list[10];
	// 10개의 메모리 공간이 항상 확보되어있다
	
	// 그러나 std::vector나 동적 메모리 할당을 사용할 때는
	// 접근하려고 하는 메모리가 제대로 잡혀있는지 allocation 돼있는지
	// 확인해봐야 한다.

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