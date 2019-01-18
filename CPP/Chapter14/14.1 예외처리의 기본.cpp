// 예외처리는 조금 느려지는 경우도 생길 수 있어서
// 퍼포먼스가 중요한 경우 자주 사용하진 않는다.

// 정말 예측할 수 없는 일이 많이 벌어지는 경우 예외처리 사용
// 인터넷 서버 같은 경우(엄마한테 들켜서 꺼버리는 경우도 있고 ..)
// 예측할 수 없는 일이 일어나도 굳건히 버티면서 서버를 유지해야 하는 경우 등

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findFirstChar(const char * string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
		if (string[index] == ch)
			return index;

	return -1; // no match
}

double divide(int x, int y, bool &success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;
	}
	success = false;
	return static_cast<double>(x) / y;
}

int main()
{
	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	std::ifstream input_file("temp.txt");
	if (!input_file)
		std::cerr << "Cannot open file" << std::endl;
}