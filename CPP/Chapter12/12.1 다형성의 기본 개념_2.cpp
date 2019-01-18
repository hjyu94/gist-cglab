// �ڽ� Ŭ������ ��ü�� �θ� Ŭ������ �����͸� ����ϸ�?
#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	virtual void speak() const
	{
		cout << m_name << " ?? " << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow ~" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof !" << endl;
	}
};

int main()
{
	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	Animal *my_animals[] = {
		&cats[0], &cats[1], &cats[2], &cats[3],
		&dogs[0], &dogs[1]
	};
	// �θ��� Ŭ���� Ÿ������ �ڽ� Ŭ������ ��ü�� ����Ű�� ���
	// �� ĳ����!
	// ���� �̷��� �θ��� �Լ��� ȣ������� ,,,

	// 'virtual' void speak() const
	// ���� �Լ��� ������ָ� ������ �Լ��� ȣ���Ѵ�
	// �� ������ '������'�̴�!
	for (auto &e : my_animals)
		e->speak();
}