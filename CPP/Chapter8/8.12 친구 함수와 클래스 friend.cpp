class A {
private:
	int m_value = 1;
};

이런 class A가 있다. 그런데 아래와 같은 함수를 만들어야 한다면

void doSomething(A& a) {
	cout << a.m_value << endl;
}

어떻게 해야할까? // 연산자 오버로딩에서 이런 경우가 많이 생긴다

1) private을 public으로 변경 // 캡슐화에 어긋나서 비추
2) doSomething 이라는 함수를 class A의 친구로 선언해버리면 된다.

/**********************************************************/

doSomething()을 class A의 친구로 선언하기

class A {
private:
	int m_value = 1;
	
	friend void doSoemthing(A& a);
};

int main() {
	A a;
	doSomething(a);
}