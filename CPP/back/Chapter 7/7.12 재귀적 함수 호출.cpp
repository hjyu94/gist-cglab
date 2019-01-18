// ����� ����� ����� �� ���� ���������� �Ű��� �Ѵ�

// recursion �� �߸� ����ϸ�
// ���� �����÷ο찡 �߻��� �� �ִ�

// ���� �����÷ο찡 �ʹ� �����ٸ�
// std::vector�� �������� ����ϴ� ��ó��ȵ� �ִ�

// recursion �� iterative���� �����ϱ� ����
// ������ recursion �� ������ ����ϱ� ������
// �����ϸ� iteration���� �ٲ㼭 ����ϴ� ���� ����.
// ������ �߿��ϴٸ� iteration�� ����ϴ� ���� ��õ�Ѵ�

#include <iostream>
using namespace std;

void countDown(int count) {
	cout << count << endl;
	if(count>0)
		countDown(count - 1);
}

int main() {
	countDown(5);
	return 0;
}