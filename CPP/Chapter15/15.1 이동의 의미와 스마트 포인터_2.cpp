// new, delete으로 동적 메모리를 사용할 때 메모리 관리가 귀찮아짐
// 이를 스마트 포인터를 사용해서 조금 더 손쉽게 사용할 수 있다.
// 이동 move semantics, smart pointers

#include "15.1 Resource.h"
#include "15.1 AutoPtr.h"
using namespace std;

int main()
{
	{
		AutoPtr<Resource> res1(new Resource); // int i; int *ptr1(&i);
		AutoPtr<Resource> res2; //  int *ptr2=nullptr;

		doSomething(res1);
		// 이렇게 넘겨주고 난 뒤에는 그 다음에 메모리가 사라질텐데
		// 이를 어떻게 처리해야 하는지를 다음의 강의들을 보면서 주의깊게 볼 것

		cout << std::boolalpha;

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;

		res2 = res1; 
		// copy assignment
		// res1의 멤버 변수들이 모두 복사되어
		// res2의 멤버 변수들에게 붙여넣기 된다.
		// 이 부분이 문제가 됨

		// 여기서 소유권을 넘겨줘야 함
		// move semantics라고 함

		// syntax vs. semantics
		// syntax: 컴파일이 되냐 안되냐
		// semantics: 컴파일이 되긴 되는데 내가 생각한 의도대로 되냐 안되냐

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}
	// res1, res2가 같은 메모리를 가지고 있는데
	// 둘 다 메모리를 지우려고 함
	// (집이 한갠데 서로 자기꺼라고 하는 상황과 비슷)
	// 소유권을 누가 갖느냐가 중요한 문제이다.

	doSomething(res1);
	// value semantics (copy semantcis)
	// reference semantics (pointer)
	// move semantics (move)
}