// 자식 클래스의 객체에 부모 클래스의 포인터를 사용하면?
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
	// 부모의 클래스 타입으로 자식 클래스의 객체를 가리키는 경우
	// 업 캐스팅!
	// 보통 이러면 부모의 함수가 호출되지만 ,,,

	// 'virtual' void speak() const
	// 가상 함수로 만들어주면 각자의 함수를 호출한다
	// 이 개념이 '다형성'이다!
	for (auto &e : my_animals)
		e->speak();
}