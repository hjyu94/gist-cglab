// new, delete���� ���� �޸𸮸� ����� �� �޸� ������ ��������
// �̸� ����Ʈ �����͸� ����ؼ� ���� �� �ս��� ����� �� �ִ�.
// �̵� move semantics, smart pointers

#include "15.1 Resource.h"
#include "15.1 AutoPtr.h"
using namespace std;

int main()
{
	{
		AutoPtr<Resource> res1(new Resource); // int i; int *ptr1(&i);
		AutoPtr<Resource> res2; //  int *ptr2=nullptr;

		doSomething(res1);
		// �̷��� �Ѱ��ְ� �� �ڿ��� �� ������ �޸𸮰� ������ٵ�
		// �̸� ��� ó���ؾ� �ϴ����� ������ ���ǵ��� ���鼭 ���Ǳ�� �� ��

		cout << std::boolalpha;

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;

		res2 = res1; 
		// copy assignment
		// res1�� ��� �������� ��� ����Ǿ�
		// res2�� ��� �����鿡�� �ٿ��ֱ� �ȴ�.
		// �� �κ��� ������ ��

		// ���⼭ �������� �Ѱ���� ��
		// move semantics��� ��

		// syntax vs. semantics
		// syntax: �������� �ǳ� �ȵǳ�
		// semantics: �������� �Ǳ� �Ǵµ� ���� ������ �ǵ���� �ǳ� �ȵǳ�

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}
	// res1, res2�� ���� �޸𸮸� ������ �ִµ�
	// �� �� �޸𸮸� ������� ��
	// (���� �Ѱ��� ���� �ڱⲨ��� �ϴ� ��Ȳ�� ���)
	// �������� ���� �����İ� �߿��� �����̴�.

	doSomething(res1);
	// value semantics (copy semantcis)
	// reference semantics (pointer)
	// move semantics (move)
}