다른 클래스에서 private 멤버 변수를 사용하고 싶은 경우

class A {
private:
	int m_value = 1;
};

class B {
private:
	int m_value = 2;

	void doSomething(A& a) {
		cout << a.m_value << endl;
	}
};

/***************************************************/

// 1 
class A 에서 class B가 내 친구라고 선언한다.

class A {
private:
	int m_value = 1;
	friend class B;
};

/***************************************************/

// 2
그런데 클래스 B의 모든 함수에 내 모든 private 멤버 변수를 넘겨주기 부담스러우면
해당 함수만 콕 집어서 얘기할수도 있다.

class A {
private:
	int m_value = 1;
	friend void B::doSomething(A& a);
};


/***************************************************/

그런데 class B가 뒤에 선언되어 있으면 앞에 전방선언 class B; 를 해줬다고 하더라도
doSomething 존재를 모른다

이런 경우 doSomething을 정의와 선언을 분리한다.

class A;

class B {
private:
	int m_value = 2;

	/*
		void doSomething(A& a) {
			cout << a.m_value << endl;
		}
	*/

	void doSomething(A& a);
};

class A {
private:
	int m_value = 1;
	
	friend void B::doSomething(A& a);
};

void B::doSomething(A& a) {
	cout << a.m_value << endl;
}