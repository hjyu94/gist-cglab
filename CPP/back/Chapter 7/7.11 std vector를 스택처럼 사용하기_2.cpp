#include <iostream>
#include <vector>

using namespace std;

void printStack(std::vector<int> &stack) {
	for (auto &e : stack)
		cout << e << " ";
	cout << endl;
}

int main() {

	// ���� ���� �÷ο찡 ���µ� ����� ����� �ݵ�� ����ؾ� �ϸ�
	// ���͸� ���� ����� �ִ�.

	std::vector<int> stack;
	stack.reserve(1024);

	// ���͸� �̿��� push, pop�� �غ���
	// �̸� ����� reserve�� �س����� <- �´��� Ȯ�� �ʿ�
	// capcity�� �����ϰ�, size�� �ٲ�� �ȴ�.

	stack.push_back(3);
	printStack(stack);
	stack.push_back(5);
	printStack(stack);
	stack.push_back(7);
	printStack(stack);

	stack.pop_back();
	printStack(stack);
	stack.pop_back();
	printStack(stack);	
	stack.pop_back();
	printStack(stack);
}

