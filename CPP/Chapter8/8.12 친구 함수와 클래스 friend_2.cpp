class A {
private:
	int m_value = 1;
};

class B {
private:
	int m_value = 2;
};

���� ���� class A,B�� �ִ�
�׷��� �Ʒ��� ���� �Լ��� �ʿ��ϴٸ�?

void doSomething(A& a, B& b) {
	cout << a.m_value << ", " << b.m_value << endl;
}

A, B Ŭ������ private ��� ������ �����ϰ� �ִ�
�׷��� doSomething�� A, B ���ο� ģ�� �Լ��� �����ؾ� �Ѵ�.

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

�׷��� ������ A���ο��� B�� ���Ǹ� �˾ƾ� �ϴµ�.. ?
->���漱���� ����ϴ� ����� �ִ�.

/**********************************************************/

class B; // forward declaration
// ������Ҷ��� �ڵ带 ���� �� �����ϱ� �ѵ�
// �ε����� ��� ����Ѵ�.

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
