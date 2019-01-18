// new, delete���� ���� �޸𸮸� ����� �� �޸� ������ ��������
// �̸� ����Ʈ �����͸� ����ؼ� ���� �� �ս��� ����� �� �ִ�.
// �̵� move semantics, smart pointers

#include "15.1 Resource.h"
#include "15.1 AutoPtr.h"
using namespace std;

// RAII : resource acquisition is initialization
// new �� ������ delete �ؾ� �Ѵٴ� ����

// Resource�� �����Ҵ� �޾Ƽ� ��������
// �¸� �̿��� �۾��� �ѵ� �޸𸮸� �ݳ��Ͽ� return �ؼ� ������.
void doSomething()
{
	try
	{
		// Resource *res = new Resource; // dull pointer
		// ���� delete�� ����� �ϴ� ������

		AutoPtr<Resource> res = new Resource; // smart pointer

		// work with res

		if (true)
		{
			throw - 1;
			// delete res;
			// return; // early return, �� ��쿡 delete �����ϱ� ����
		}
	}
	catch (...)
	{
		cout << "this is caught" << endl;
	}
	// delete res;
	// delete: 
	// �� �̻� �� �޸𸮸� ������� �ʰڴ�!
	// OS�� ������!! �ݳ���

	return;
}

int main()
{
	doSomething();
}