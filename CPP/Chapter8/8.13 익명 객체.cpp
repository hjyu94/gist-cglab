#include <iostream>
using namespace std;

class A {
public:
	int m_value;
	
	A(const int& v)
		: m_value(v) {
		cout << "Constructor" << endl;
	}
	
	~A(){
		cout << "Destructor" << endl;
	}

	void printDouble() {
		cout << m_value * 2 << endl;
	}
};

int main() {
	A a(1);
	a.printDouble();

	A(2).printDouble(); 
	// A(2)가 r-value로 작동한다
	// 생성된 객체를 재활용할 수 없는 익명객체이다.

	return 0;
}