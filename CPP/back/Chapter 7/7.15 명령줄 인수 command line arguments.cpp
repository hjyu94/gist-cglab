#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	for (int count = 0; count < argc; ++count) {
		cout << argv[count] << endl;
	}
}

// C:\Users\CGLab5\Desktop\hjeong\C++\CPP\x64\Debug\Chapter7.exe

// 1) 커맨드 라인에서 직접 실행해야 함
// cd ...
// Chapter7.exe Hello World

// 2) Properties
// Configuration Properties - Debugging
//    - Command Arguments에 Hello World 입력
