#include "Student.h"
#include "Teacher.h"

int main()
{
	Student std("Jack Jack");
	Teacher teacher1("Dr. H");

	std::cout << std << std::endl;
	std::cout << teacher1 << std::endl;

	std.doNothing();
	teacher1.doNothing();

	std.study();
	teacher1.teach();
	
	Person person;
	person.setName("Mr. Incredible");
	person.study(); // error
	person.teach(); // error
}