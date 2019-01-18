#include <iostream>
#include <vector>

using namespace std;

int main() {
	// ���� �迭
	// std::array<int, 5> array;

	// ���� �迭
	std::vector<int> array;

	std::vector<int> array2 = { 1,2,3,4,5 };
	cout << array2.size() << endl;

	std::vector<int> array3 = { 1,2,3, };
	cout << array3.size() << endl << endl;


	std::vector<int> array4 { 1,2,3, }; // uniform initialization
	cout << array4.size() << endl;
	for (auto &itr : array4)
		cout << itr << " ";
	cout << endl << endl;
	
	array4.resize(10);
	cout << "resize ����" << endl;
	cout << array4.size() << endl;
	for (auto &itr : array4)
		cout << itr << " ";
	cout << endl << endl;

	// ������?
	int *my_arr = new int[5];
	delete[] my_arr;
	// ���� �����Ҵ��� �� �� �ڿ��� ������ �Ѵ�
	// �׷��� vector�� ��� �˾Ƽ� �������� ������
	// �޸𸮰� ���� �ʴ´�.
	// ���� size(), at(), start(), end(), resize(10) ���� �Լ��� ����� �� �ִ�.

	return 0;
}