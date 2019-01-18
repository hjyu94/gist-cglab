#include <iostream>
using namespace std;

class Simple {
private:
	int m_id;
public:
	Simple(const int& id_in) : m_id(id_in) {
		cout << "Constructor " << m_id << endl;
	}

	~Simple() {
		cout << "Destructor " << m_id << endl;
	}
};


class IntArray {
private:
	int *m_arr = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in) {
		m_length = length_in;
		m_arr = new int[m_length];
		
		cout << "Constructor" << endl;
	}

	~IntArray() {
		if(m_arr != nullptr)
			delete[] m_arr; 
		// vector 내부에서는 이처럼 소멸자에서 delete를 해준다. 근데 얘들은 속도가 느리니 조심해야 한다.
	}

	int getLength() {
		return m_length;
	}
};

int main() {
	//Simple s1(0);
	Simple *s1 = new Simple(0); // 동적 할당
	Simple s2(1);

	delete s1;

	cout << endl;

	while (true) {
		IntArray my_int_arr(10000); // memory leak
	} 
	return 0;
}