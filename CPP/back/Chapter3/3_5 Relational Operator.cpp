#include <iostream>

using namespace std;

int main() {
	// 부동소수의 크기를 비교하는 것은
	// 사람과 다른 결과를 출력할 때가 있다.
	
	// 이 때 대응하는 방법 중 하나는 오차의 한계를 지정하고
	// 오차보다 작으면 거의 비슷하다고 보는 것.

	double d1(100 - 99.99); // 0.001
	double d2(10 - 9.99); // 0.001

	if (d1 == d2)
		cout << "equal" << endl;
	else {
		cout << "Not equal" << endl;
		if (d1 > d2) cout << "d1>d2" << endl;
		else cout << "d1<d2" << endl;

		cout << abs(d1 - d2) << endl;
	}

	const double epsilon = 1e-10;
	if (abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;

	return 0;
}