/*
std::array, std::vector는
함수를 호출하는 대신에
[] 연산자를 사용해 값을 접근하거나 바꾼다
[] 연산자의 오버로딩
*/

#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };

public:
	int & operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);
		// if문으로 거르는것보다 빠르다

		return m_list[index];
	}

	const int & operator [] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}
};

int main()
{
	IntList my_list;
	my_list[3] = 10;
	cout << my_list[3] << endl;

	const IntList const_list;
	cout << const_list[3] << endl;

	/************************************/

	IntList *list = new IntList;
	
	list[3] = 10;
	list[3] = IntList();
	
	(*list)[3] = 10;
	// 이런식으로 사용해야 된다.
}