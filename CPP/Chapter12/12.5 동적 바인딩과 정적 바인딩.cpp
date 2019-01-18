#include <iostream>
using namespace std;

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x*y; }

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0~2: add subtract multiply" << endl;

	/******************************************/

	// static binding (early binding)
	int result;
	switch (op)
	{
	case 0:
		result = add(x, y); break;
	case 1:
		result = subtract(x, y); break;
	case 2:
		result = multiply(x, y); break;
	}

	cout << result << endl;
	
	/******************************************/

	// dynamic binding (late binding)
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0:
		func_ptr = add; break;
	case 1:
		func_ptr = subtract; break;
	case 2:
		func_ptr = multiply; break;
	}

	cout << func_ptr(x, y) << endl;
	
	// func_ptr가 어떤 함수의 주소가 될 지
	// 런타임에 결정 된다.
	
	// 값을 구해낼때(func_ptr(x,y))도 동적으로 할당된 주소를 찾아가서
	// 주소 자리에 있는 함수를 사용해 값을 찾는 
	// 간접적인 방식을 사용하고 있다.

	/******************************************/

	return 0;
}

/*			static binding		dynamic binding
	속도			빠르다				느리다
	유연성		낮다					높다
*/

// 유연한 프로그래밍이 필요할때 동적 바인딩이 매우 유용하다