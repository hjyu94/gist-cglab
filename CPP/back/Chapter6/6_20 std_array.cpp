#include <iostream>
#include <array>

using namespace std;

void printLength(array<int, 5> my_arr) { 
	// �����ؼ� �Ѿ�� ������ �ӵ��� ������ ���� �ִ�, 
	// �ӵ��� �߿��� ����� ���� �������� �ʰ� ��ġ�� �Ѱ��ִ�
	// ���۷��� �����͸� ���°��� ����.
	cout << my_arr.size() << endl;
}

int main() {
	//int array[5] = { 1,2,3,4,5 };
	array<int, 5> my_arr = { 1,2,3,4,5 };
	my_arr = { 1,2, }; // ������ ���ڸ��� 0���� ä���ش�
	
	//cout << my_arr[10] << endl; // �´��� �ȸ´��� ������� �׳� ������ѹ�����
	//cout << my_arr.at(10) << endl; // ����ó���� �Ѵ�-> �����ս��� ���������� �ִٴ� ������ �ִ�.
	cout << my_arr.size() << endl; // sizeof(my_arr) / sizeof(int)
	printLength(my_arr);

	
	array<int, 5> my_arr2 = { 1,21,3,40,2 };
	
	cout << "���� ��" << endl;
	for (auto &element : my_arr2) // ���۷����� �Ѱ��ָ� �ӵ��� ��������.
		cout << element << " ";
	cout << endl;

	std::sort(my_arr2.begin(), my_arr2.end());
	
	cout << "���� ��" << endl;
	for (auto &element : my_arr2)
		cout << element << " ";
	cout << endl;

	my_arr2 = { 1,21,3,40,2 };
	std::sort(my_arr2.rbegin(), my_arr2.rend());

	cout << "r ���� ��" << endl;
	for (auto &element : my_arr2)
		cout << element << " ";
	cout << endl;

	return 0;
}