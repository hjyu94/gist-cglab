#include <iostream>

using namespace std;

int getInt() {
	while (true) {
		cout << "Enter an integer number : ";
		int x;
		cin >> x;

		if (std::cin.fail()) { // 너무 큰 수가 입력되면 cin.fail()이 true를 반환한다.
			std::cin.clear();
			std::cin.ignore(32767, '\n'); // 적당히 큰 수 32767, 버퍼에 남아있는 값을 지우자.
			cout << "Invalid number, please try again" << endl;
		}
		else {
			std::cin.ignore(32767, '\n'); // 적당히 큰 수 32767, 버퍼에 남아있는 값을 지우자.
			return x;
		}
	}
}

char getOperator() {
	while (true) {
		cout << "Enter an operator (+, -) : ";
		char op;
		cin >> op;
		std::cin.ignore(32767, '\n');

		if (op == '+' || op == '-') {
			return op;
		}
		else {
			cout << "Invalid operator, please try again" << endl;
		}
	}
}

int main() {
	int x = getInt();
	char op = getOperator();
	int y = getInt();

}