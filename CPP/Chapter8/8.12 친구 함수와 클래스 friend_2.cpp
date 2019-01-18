class A {
private:
	int m_value = 1;
};

class B {
private:
	int m_value = 2;
};

위와 같이 class A,B가 있다
그런데 아래와 같은 함수가 필요하다면?

void doSomething(A& a, B& b) {
	cout << a.m_value << ", " << b.m_value << endl;
}

A, B 클래스의 private 멤버 변수를 접근하고 있다
그러면 doSomething을 A, B 내부에 친구 함수로 선언해야 한다.

/**********************************************************/

class A {
private:
	int m_value = 1;

	friend void doSomething(A& a, B& b);
};

class B {
private:
	int m_value = 2;

	friend void doSomething(A& a, B& b);
};

그런데 문제는 A내부에서 B의 정의를 알아야 하는데.. ?
->전방선언을 사용하는 방법이 있다.

/**********************************************************/

class B; // forward declaration
// 디버깅할때나 코드를 읽을 때 불편하긴 한데
// 부득이한 경우 사용한다.

class A {
private:
	int m_value = 1;

	friend void doSomething(A& a, B& b);
};

class B {
private:
	int m_value = 2;

	friend void doSomething(A& a, B& b);
};
