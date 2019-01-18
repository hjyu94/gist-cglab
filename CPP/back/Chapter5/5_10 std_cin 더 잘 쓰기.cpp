#include <iostream>

using namespace std;

int getInt() {
	while (true) {
		cout << "Enter an integer number : ";
		int x;
		cin >> x;

		if (std::cin.fail()) { // �ʹ� ū ���� �ԷµǸ� cin.fail()�� true�� ��ȯ�Ѵ�.
			std::cin.clear();
			std::cin.ignore(32767, '\n'); // ������ ū �� 32767, ���ۿ� �����ִ� ���� ������.
			cout << "Invalid number, please try again" << endl;
		}
		else {
			std::cin.ignore(32767, '\n'); // ������ ū �� 32767, ���ۿ� �����ִ� ���� ������.
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