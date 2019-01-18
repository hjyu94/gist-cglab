#include <iostream>

using namespace std;

class Something
{
public:
	
	int m_value = 0;

	// default copy constructor
	Something(const Something& st_in) {
		m_value = st_in.m_value;
	}

	Something() {
		cout << "constructor" << endl;
	}

	void setValue(int value) { 
		m_value = value; 
	}

	void setValue(int value) const {
		m_value = value;
	}
	// const 함수에서는 멤버변수의 값을 바꿀 수 없다.
	
	int getValue() const 
	{ 
		return m_value; 
	}
	// 멤버 함수가 const라는 것은
	// 함수 내부에서 멤버 변수의 값을 바꾸지 않겠다는 의미.
	// 따라서 const로 만든 인스컨스가 해당 함수를 호출하려면
	// 해당 함수도 const 함수여야 한다.

	// 따라서 const 함수로 만들 수 있으면 모두 const 함수로
	// 만드는 것이 나중에 혹시 const 인스턴스를 찍을 때를 대비해서
	// 유리하다.
};

void print(Something st) {
	// 값이 복사된다
	// 이 때 copy constructor가 호출된다.
	cout << &st << endl;
	cout << st.m_value << endl;
}

void print_reference(const Something& st) {
	// 가장 효율적임
	cout << &st << endl;
	cout << st.m_value << endl;
	cout << "주소가 같다" << endl;
}

class Something2 {
public:
	string m_value = "default";
	
	const string& getValue() const { 
		cout << "Const version" << endl;
		return m_value; 
	}

	string& getValue() { 
		cout << "non-const version" << endl;
		return m_value; 
	}
};

int main() {
	// 인스턴스, 오브젝트, 변수 만들기
	const Something something; // 멤버변수를 const로 만듦
	
	something.setValue(3); 
	// const 인스턴스의 멤버변수를 바꾸려고 하면 문제가 생김
	
	cout << something.getValue() << endl;
	// 값을 출력하는데도 문제가 생김.
	// const의 인스턴스의 멤버 함수를 호출하려면
	// 그 멤버 함수가 const여야 한다.
	// int getValue() 'const' 로 바꿔주자.
	// const 함수 내에서는 멤버 값을 바꾸지 않을 것이다는 것을 명시하는 것.
	
	// 즉 instance를 const로 만든 경우에는
	// 멤버 변수들이 const로 만들어지고
	// const인 멤버 함수들만 사용 가능하다
	
	// 팁 : 
	// const로 만들 수 있는 함수는 const로 만드는 것이
	// 나중에 디버깅에 유리하다.

	cout << endl;


	////////////////////////////////////////////////////////////////////////


	Something sth;
	cout << &sth << endl;
	print(something);

	print_reference(sth);

	cout << endl;


	////////////////////////////////////////////////////////////////////////
	

	Something2 sth1;
	sth1.getValue() = 10;

	const Something2 sth2;
	sth2.getValue() = 9999; // 에러

}