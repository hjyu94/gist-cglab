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
	// throw �ϴ� Ÿ�Կ� ���� �ٸ� ���� �����Ų��.
	// data type �� ��Ȯ��! ������� ��Ÿ�� ������ ���� �ʴ´�.
	// Ȥ�� �´� data type�� ��� �ƹ������� ������� ���ϸ� ��Ÿ�� ����
	return 0;
}