#include <iostream>
#include <array>

using namespace std;

int main() {
	//int array[5] = { 1,2,3,4,5 };
	array<int, 5> my_arr = { 1,2,3,4,5 };
	my_arr = { 1,2, }; // ������ ���ڸ��� 0���� ä���ش�

	cout << my_arr[10] << endl; // �´��� �ȸ´��� ������� �׳� ������ѹ�����
	cout << my_arr.at(10) << endl; // ����ó���� �Ѵ�-> �����ս��� ���������� �ִٴ� ������ �ִ�.
}