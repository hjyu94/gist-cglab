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

	void speak() const
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
	Animal animal("my animal");
	Cat cat("my cat");
	Dog dog("my dog");

	animal.speak();
	cat.speak();
	dog.speak();

	Animal *ptr_animal1 = &cat;
	Animal *ptr_animal2 = &dog;

	ptr_animal1->speak();
	ptr_animal2->speak();
	// �ڱⰡ �θ� Ŭ�������� �˰� �۵��� ��
	// Animal::speak()�� ȣ���

	cout << endl;

	/****************************************************************/

	Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4") };
	Dog dogs[] = { Dog("dog1"), Dog("dog2") };

	for (auto &e : cats)
		e.speak();

	for (int i = 0; i < 2; ++i)
		dogs[i].speak();

	cout << endl;
	
	// ...
	// ���� cats, dogs, ������s, Ļ�ŷ�s, �� ������
	// for ���� �� �������� ������ �ϴµ� ������
	// Animal class�� �̿��ؼ� ��� �� ������

	/****************************************************************/

	Animal *my_animals[] = {
		&cats[0], &cats[1], &cats[2], &cats[3],
		&dogs[0], &dogs[1]
	};

	for (auto &e : my_animals)
		e->speak();
}