// ���� �Ҵ� �޸𸮸� ���� ����ϴ� �ͺ���
// vector �� ���� ���� �ξ� ����.

// �� ������ ����,
// ���������� ���Ǵ� new�� delete�� ���� ���Ǵ� �������� ����� ���� ȿ����

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// int *v_ptr = new int[3]{1,2,3}; �� ����� ��Ȳ	
	std::vector<int> v{ 1,2,3 };

	// size, capacity ����!
	// ��ü capacity �� ���� ����� ���� size��� �����ϸ� �ȴ�
	
	v.resize(2);
	for (unsigned int i = 0; i<v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	// 1,2,3 �� 1,2�� ��µȴ�

	cout << "size:" << v.size() << ", capacity: " << v.capacity() << endl;
	
	// �׷��� v[2]�� ��������ϱ�?
	
	// cout << v[2] << endl;
	// cout << v.at(2) << endl;
	// ��Ÿ�� ���� !! 

	int *ptr = v.data();
	cout << ptr[2] << endl;
	// �̷��� ����ϸ� v[2]�� ���´�.

	// �� ���� ��,
	// �� ���� ������ resize�� �� (v.resize(2))
	// ���ο� �޸𸮸� �Ҵ��� �� ���� ������ 3�� �� 2���� �����Ͽ�
	// ���ο� �޸𸮿� �����ϰ� ���� �޸𸮸� �ݳ��ϴ� ���� �ƴ϶�
	// �ӵ� ����� ���� new, delete ����� �ƴ϶� �׳� ���̾��� ��ġ�� ����� �� �ְ� �Ϸ��ߴ� ��.

	cout << endl << endl;
	

	// size�� capacity ���� �ø��� ��� � ���� ���⳪?

	cout << "size 10���� ����" << endl;
	v.resize(10);
	for (auto &e : v)
		cout << e << " ";
	cout << endl << endl;

	cout << "v �ٽ� �ʱ�ȭ" << endl;
	v = std::vector<int>{ 1,2,3 };
	cout << "capacity 1024���� ����" << endl;
	
	// reverse�� �޸��� �뷮�� �̸� Ȯ���� ���ڴٴ� �ǹ�
	v.reserve(1024);
	
	for (auto &e : v)
		cout << e << " ";
	cout << endl << endl;
	// �� reverse�� ����ؼ� ����� capacity�� Ȯ���� �δ� ��찡 �ֳĸ�
	// �ڿ� ���Ұ� �߰��� �� �޸𸮸� �޾ƿ��� �۾��� ���ʿ��ؼ�
	// �ִ��� new, delete�� ���̴� �������� ����ϴ� ��.
}
