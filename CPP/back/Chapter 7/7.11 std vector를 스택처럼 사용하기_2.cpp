#include <iostream>
#include <vector>

using namespace std;

void printStack(std::vector<int> &stack) {
	for (auto &e : stack)
		cout << e << " ";
	cout << endl;
}

int main() {

	// 스택 오버 플로우가 나는데 재귀적 용법을 반드시 사용해야 하면
	// 벡터를 쓰는 방법이 있다.

	std::vector<int> stack;
	stack.reserve(1024);

	// 벡터를 이용해 push, pop을 해보자
	// 미리 충분히 reserve를 해놓으면 <- 맞는지 확인 필요
	// capcity는 유지하고, size만 바뀌게 된다.

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

