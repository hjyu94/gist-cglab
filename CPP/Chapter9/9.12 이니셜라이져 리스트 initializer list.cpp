#include <iostream>
#include <cassert>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int *m_data = nullptr;

public:
	// 길이를 입력 받으면 메모리를 할당받는다
	IntArray(unsigned length)
		: m_length(length)
	{
		m_data = new int[length];
	}

	IntArray(const std::initializer_list<int> & list)
		: IntArray(list.size()) // IntArray(unsigned length) 생성자 호출
	{
		int count = 0;
		for (auto & e : list)
		{
			m_data[count] = e;
			++count;
		}

		for (unsigned count = 0; count < list.size(); ++count)
			m_data[count] = list[count]; // error
		// initializer list 는 [] 를 제공하지 않는다.
	}

	friend ostream & operator << (ostream & out, IntArray & arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}
	
};

int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int *my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto il = { 10,20,30 };
	// initializer_list<int> type
	
	/*
		우리가 만든 클래스도 initializer list로 받고 싶은데
		IntArray(const std::initializer_list<int> & list)
		함수를 만들어 놓지 않으면 에러가 난다.

		IntArray int_array{ 1,2,3,4,5 };
		cout << int_array << endl;
	*/
	
	IntArray int_array{ 1,2,3,4,5 };
	cout << int_array << endl;
	
	return 0;
}