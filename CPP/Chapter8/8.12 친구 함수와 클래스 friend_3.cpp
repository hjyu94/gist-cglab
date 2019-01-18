�ٸ� Ŭ�������� private ��� ������ ����ϰ� ���� ���

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
class A ���� class B�� �� ģ����� �����Ѵ�.

class A {
private:
	int m_value = 1;
	friend class B;
};

/***************************************************/

// 2
�׷��� Ŭ���� B�� ��� �Լ��� �� ��� private ��� ������ �Ѱ��ֱ� �δ㽺�����
�ش� �Լ��� �� ��� ����Ҽ��� �ִ�.

class A {
private:
	int m_value = 1;
	friend void B::doSomething(A& a);
};


/***************************************************/

�׷��� class B�� �ڿ� ����Ǿ� ������ �տ� ���漱�� class B; �� ����ٰ� �ϴ���
doSomething ���縦 �𸥴�

�̷� ��� doSomething�� ���ǿ� ������ �и��Ѵ�.

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