class A {
private:
	int m_value = 1;
};

�̷� class A�� �ִ�. �׷��� �Ʒ��� ���� �Լ��� ������ �Ѵٸ�

void doSomething(A& a) {
	cout << a.m_value << endl;
}

��� �ؾ��ұ�? // ������ �����ε����� �̷� ��찡 ���� �����

1) private�� public���� ���� // ĸ��ȭ�� ��߳��� ����
2) doSomething �̶�� �Լ��� class A�� ģ���� �����ع����� �ȴ�.

/**********************************************************/

doSomething()�� class A�� ģ���� �����ϱ�

class A {
private:
	int m_value = 1;
	
	friend void doSoemthing(A& a);
};

int main() {
	A a;
	doSomething(a);
}