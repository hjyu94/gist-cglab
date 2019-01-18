// �����Ϸ��� ������ �޾Ƽ� ����� �ð��� ������

#include <iostream>
#include <cassert> // assert.h
#include <array>

using namespace std;

void printValue(const std::array<int, 5> &my_array, const int& ix) {
	// �Ķ���Ϳ� ���۷��� ���� ��� -> �ּҸ� �����ؿ�.
	// ������ ���� �Ѱ��ٶ����� �� �� ���ϰ� ��� ����
	// const�� ���� ���� -> �Լ� ���ο��� �Ķ���� ���� �ٲ��� �ʵ��� �Ϸ���
	
	// �� ���� �� ��� ���� �������� �˷��� �� ������ ���ָ� �ȴ�.
	// assert(ix >= 0 && ix <= my_array.size() - 1);
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1);

	std::cout << my_array[ix] << std::endl;
}

int main() {
	// ����� ��忡�� ����Ʈ��� �׽�Ʈ �� ���� �۵�

	// �Ӽ� - Preprocessor - 
	//    preprocessor definitions�� WIN32;NDEBUG ���� ������ �۵� ����  

	// release ��忡�� ������ ���α׷��� ������ ���ƾ� �ϱ� ������
	// assert�� �۵����� �ʴ� ��

	// assert(false);

	/**************************************************/

	int number = 5;
	
	// ...
	// �� �������� number�� ���� �ٲ� ���� �ִµ� ...

	assert(number == 5);
	// number should be 5
	// ���� �ٿ��� �ݵ�� 5���� �Ѵٸ�
	// �����ڿ��� �ּ��� ������� �ϴ� �ͺ���
	// �����Ϸ��� ������ ���ִ°� ������ �ȴ�.

	/**************************************************/

	std::array<int, 5> my_array{ 1,2,3,4,5 };
	
	printValue(my_array, 100);
	// Assertion failed: ix >= 0 && ix <= my_array.size() - 1, file c:\users\cglab5\desktop\hjeong\c++\c++\chapter 7\7.14 �ܾ� �ϱ� assert.cpp, line 14
	
	return 0;
}