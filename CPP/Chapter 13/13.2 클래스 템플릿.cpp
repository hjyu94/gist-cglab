#include "MyArray.h"

/*
	둘 다 가능.
	template<typename T>; 
	template<class T>;
*/

int main()
{
	// MyArray my_array(10);
	MyArray<char> my_array(10);

	for (int i = 0; i < my_array.getLength(); ++i) 
		my_array[i] = i + 65;
	
	my_array.print();

	return 0;
}