#include <iostream>

using namespace std;

int main() {
	float a;
	
	// 1. sizeof는 함수가 아니라 연산자이다.
	cout << sizeof(float) << endl; // 데이터 타입(class, struct 포함)
	cout << sizeof(a) << endl; // 변수
	cout << sizeof a << endl; // 변수

	// 2. comma operator
	int x = 3;
	int y = 10;
	int z = (++x, ++y); // 보통 ++x; ++y; z = y; 이렇게 쓰는데 반복문에서는 comma operator를 많이 사용한다.

	cout << x << ", " << y << ", " << z << endl;

	int a = 1, b = 10;
	// 이 경우는 comma operator가 아니다. 우선순위 때문인데, =의 우선순위가 , 보다 높아서
	// (z=a), b 의 경우가 된다.
	z = a, b; 
	cout << z << endl;

	z = (++a, a + b);
	cout << z << endl;


	// 3. conditional operator, arithmetric if
	// 3항 연산자

	bool onSale = true;
	int price;
	if (onSale)
		price = 10;
	else
		price = 100;

	// 그런데 price를 상수로 쓰고 싶다면?
	// 이때 conditional operator를 쓰면 된다!
	const int price = (onSale == true) ? 10 : 100;

	// 혹은 함수를 새로 만들어서 다른 return값을 받아올 수 있다.
	const int price = getPrice(onSale);

	return 0;
}