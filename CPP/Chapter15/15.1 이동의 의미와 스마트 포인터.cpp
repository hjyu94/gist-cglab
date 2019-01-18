// new, delete으로 동적 메모리를 사용할 때 메모리 관리가 귀찮아짐
// 이를 스마트 포인터를 사용해서 조금 더 손쉽게 사용할 수 있다.
// 이동 move semantics, smart pointers

#include "15.1 Resource.h"
#include "15.1 AutoPtr.h"
using namespace std;

// RAII : resource acquisition is initialization
// new 한 곳에서 delete 해야 한다는 개념

// Resource를 동적할당 받아서 가져오고
// 걔를 이용해 작업을 한뒤 메모리를 반납하여 return 해서 나간다.
void doSomething()
{
	try
	{
		// Resource *res = new Resource; // dull pointer
		// 직접 delete를 해줘야 하는 포인터

		AutoPtr<Resource> res = new Resource; // smart pointer

		// work with res

		if (true)
		{
			throw - 1;
			// delete res;
			// return; // early return, 이 경우에 delete 깜박하기 쉬움
		}
	}
	catch (...)
	{
		cout << "this is caught" << endl;
	}
	// delete res;
	// delete: 
	// 더 이상 이 메모리를 사용하지 않겠다!
	// OS야 가져가!! 반납함

	return;
}

int main()
{
	doSomething();
}