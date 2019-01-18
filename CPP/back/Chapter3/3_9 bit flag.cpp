#include <iostream>
#include <bitset>

using namespace std;

int main() {
	/*
		아이템 개수 만큼 플래그를 만들기
		아이템 1을 가지고 있는지 아닌지를 T/F로 나타낼 수 있다.

		bool item1_flag = false;

		// event
		item1_flag = true;

		// die?
		item1_flag = false;

		if (item1_flag == true) {
		// you can enter that door
		}

		invokeEvent(item1_flag, item2_flag, item3_flag, ...);
		// 아이템을 갖고 있는지 여부에 따라서
		// 이벤트를 발동시킬지 말지 결정.
	*/


	// 그런데 생각해보면 bool은 1바이트라서 8가지 경우를 나타낼 수 있는데 이를 이용해보자.

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

	// item2는 가지고 있고 item1이 없다면
	// 2를 잃게 하고 1을 얻게 하자.
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

	// 실질적인 예
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// 옵션이 너무 많아지는 것을 방지하기 위해 비트 플래그를 사용할 수 있다.

	// 원래는 각 아이템마다 1바이트씩 차지하는 boolean 값을 사용했었는데
	// 비트 플래그를 사용해서 상황을 나타내게 되면
	// 1비트로 한 상황씩 표현 할 수 있으므로
	// boolean으로 표현했을 때 보다 메모리를 절약할 수 있다
	// 그러므로 속도가 빨라진다.

}