#include <iostream>
#include <bitset>

using namespace std;

int main() {
	/*
		������ ���� ��ŭ �÷��׸� �����
		������ 1�� ������ �ִ��� �ƴ����� T/F�� ��Ÿ�� �� �ִ�.

		bool item1_flag = false;

		// event
		item1_flag = true;

		// die?
		item1_flag = false;

		if (item1_flag == true) {
		// you can enter that door
		}

		invokeEvent(item1_flag, item2_flag, item3_flag, ...);
		// �������� ���� �ִ��� ���ο� ����
		// �̺�Ʈ�� �ߵ���ų�� ���� ����.
	*/


	// �׷��� �����غ��� bool�� 1����Ʈ�� 8���� ��츦 ��Ÿ�� �� �ִµ� �̸� �̿��غ���.

	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;
	// opt 4,5,6,7

	cout << bitset<8>(opt0) << endl;
	cout << bitset<8>(opt1) << endl;
	cout << bitset<8>(opt2) << endl;
	cout << bitset<8>(opt3) << endl;

	unsigned char items_flag = 0;
	cout << "No item : " << bitset<8>(items_flag) << endl;

	// item0 on
	items_flag |= opt0;
	cout << "Item0 obtained : " << bitset<8>(items_flag) << endl;

	// item3 on
	items_flag |= opt3;
	cout << "Item3 obtained : " << bitset<8>(items_flag) << endl;

	// item3 lost
	// items_flag &= ~opt3;
	// cout << "Item3 lost: " << bitset<8>(items_flag) << endl;

	// has item1 ?
	if (items_flag & opt1) cout << "Has item1 : " << bitset<8>(items_flag & opt1) << endl;
	else cout << "Not have item1 : " << bitset<8>(items_flag & opt1) << endl;

	// has item0 ?
	if (items_flag & opt0) cout << "Has item0 : " << bitset<8>(items_flag & opt0) << endl;
	else cout << "Not have item0 : " << bitset<8>(items_flag & opt0) << endl;

	// obtain item 2, 3
	items_flag |= (opt2 | opt3);
	cout << "(opt2 | opt3) : " << bitset<8>(opt2 | opt3) << endl;
	cout << "Item 2, 3 obtained : " << bitset<8>(items_flag) << endl;

	// item2�� ������ �ְ� item1�� ���ٸ�
	// 2�� �Ұ� �ϰ� 1�� ��� ����.
	if ((items_flag & opt2) && !(items_flag & opt1)) {
		// 0 0 -> 0
		// 1 1 -> 0
		// 1 0 -> 1

		/*
			items_flag ^= opt2; // 1101 ^ 0100 -> 1001
			items_flag ^= opt1; // 1001 & 0010 -> 1011
		*/

		items_flag ^= (opt1 | opt2);
	}

	cout << bitset<8>(items_flag) << endl;

	// �������� ��
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// �ɼ��� �ʹ� �������� ���� �����ϱ� ���� ��Ʈ �÷��׸� ����� �� �ִ�.

	// ������ �� �����۸��� 1����Ʈ�� �����ϴ� boolean ���� ����߾��µ�
	// ��Ʈ �÷��׸� ����ؼ� ��Ȳ�� ��Ÿ���� �Ǹ�
	// 1��Ʈ�� �� ��Ȳ�� ǥ�� �� �� �����Ƿ�
	// boolean���� ǥ������ �� ���� �޸𸮸� ������ �� �ִ�
	// �׷��Ƿ� �ӵ��� ��������.

}