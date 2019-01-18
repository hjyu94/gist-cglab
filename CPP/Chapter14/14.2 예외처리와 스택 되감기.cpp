/*
	예외처리와 스택 되감기(Stack unwinding)

	함수가 함수를 호출하고, 그 함수 내에서 다른 함수를 호출한다면
	스택에 함수들이 착/ 착/ 착/ 쌓여나가게 된다.

	가장 안쪽에 있는 함수가 예외를 던진다면
	스택을 되감아가면서 어디서 예외를 받을지 찾게 된다.

	잡지 못하면 스택을 되감기 하면서 계속 날라간다
*/

#include <iostream>
using namespace std;

/*
	void last() throw(data type) exception specifier
	data type에 int가 오던 char가 오던
	void last() throw(...) exception specifier
	와 같다고 처리한다

	예외를 처리할 수 있는 함수다는 걸 알려주기 위해서 사용하긴 함
	별 능력은 없음

	단, 빈칸으로 두면 안됨
	void last() throw() exception specifier
	는 이 함수는 예외를 안 던질거에요! 라는 표현

	void last() throw(int)
	{ 
		... 
	}
*/
void last()
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;

	throw - 1;

	cout << "End last" << endl;
}

void third()
{
	cout << "Third" << endl;

	last();
	
	cout << "End third" << endl; // 1 실행 안됨
}

void second()
{
	cout << "Second" << endl;
	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught int exception" << endl;
	}

	// catch 가 있지만 해당하는 data type을 잡는 경우가 없어서
	// 또 날라감

	cout << "End second " << endl; // 2 실행 안됨
}

void first()
{
	cout << "First" << endl;
	try
	{
		second();
	}
	//catch (int) // 드디어 여기서 잡음
	//{
	//	cerr << "First caught int exception" << endl;
	//}
	catch (int *)
	{
		cerr << "First caught int exception" << endl;
	}

	cout << "End first " << endl;
}

int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		// std::cout, std::cerr, std::clog
		// 콘솔에 뭔가를 출력하는 채널이 여러가지가 있다고 알면 됨

		cerr << "main caught int exception" << endl;
	}

	// uncaught exceptions
	catch (...) // catch-all handlers 최후의 보루
	{
		cerr << "main caught ellipses exception" << endl;
	}
	cout << "End main" << endl;

	return 0;
}
