#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Object
// ���� + �Լ�

class Friend {
public: 
// access specifier (public, private, protected), 
// struct�� �⺻���� public

	string m_name;
	string address;
	int age;
	double height, weight;

	void print() {
		cout << m_name << " " << address << endl;
	}

};

//// fr. �� ��� ���°� ����������. Friend ����ü �ȿ��� �����ϸ� �ȴ�.
//void print(const Friend &fr) {
//	cout << fr.name << " " << fr.address << endl;
//}

void print(const string &name, const string &address, const int &age,
	const double &height, const double &weight)
{
	cout << name << " " << address << endl;
}

int main() {
	Friend jj{ "a","b",1,2,3 }; // uniform initialization
	// ������ �޸𸮸� �����ϰ� ���ִ� ��. instanciation, instance
	// �����ϴ��� �ƴ����� ���δ� �޸𸮸� �����ϰ� �ִ����� Ȯ���Ѵ�.

	jj.m_name = "Jack Jack";

	print(jj.m_name, jj.address, jj.age, jj.height, jj.weight); // member variables
	jj.print();

	vector<string> name_vec;
	vector<string> addr_vec;
	vector<int> age_vec;
	vector<double> height_vec;

	print(name_vec[0], addr_vec[0], 0, 0, 0); // ...

	vector<Friend> my_friends;
	my_friends.resize(2);
	my_friends[0].print();
	my_friends[1].print();

	// õ���̸� ���...?
	for (auto &ele : my_friends)
		ele.print();
}