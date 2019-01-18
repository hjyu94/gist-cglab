#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// try, catch, throw
	try
	{
		// something happened
		throw 1.0;
	}
	catch (double x)
	{
		cout << "Catch double " << x << endl;
	}
	catch (int x)
	{
		cout << "Catch integer " << x << endl;
	}
	// throw 하는 타입에 따라 다른 일을 실행시킨다.
	// data type 을 정확히! 적어줘야 런타임 에러가 나지 않는다.
	// 혹은 맞는 data type이 없어서 아무데서도 잡아주지 못하면 런타임 에러
	return 0;
}