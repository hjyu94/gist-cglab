#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

/* 
	- 링킹 에러
	: main.cpp 에서 include "MyArray.h"를 하면
	: 헤더 파일이 main.cpp에 있는 것처럼 작동한다
	: MyArray<char> MyArray를 char 데이터 타입에 대해서
	: 인스턴시에이션 해야한다는 것 까지는 컴파일러가 알 수 있다
	
	: 그런데 문제는,
	: print()라는 멤버 함수를 컴파일 할때는
	: MyArray.cpp 에서 컴파일을 하기 때문에
	: main.cpp에서는 MyArray.cpp를 include하지 않는다

	: 그래서
	: MyArray.cpp에 있는 print() 함수를 인스턴시에이션할때
	: char로 해야한다는 것을 모르기 때문에 생기는 에러

	: MyArray라는 templatized된 클래스를 인스턴시에이션 할 때
	: 어떤 타입으로 해야 하는지를 
	: MyArray.h를 컴파일 할 때는 알 수가 없다.

	[해결법]
	1/ #include "MyArray.cpp"는 하면 안된다!
	2/ MyArray.cpp 에서 print()를 컴파일 할 때
	특정 데이터 타입으로 컴파일 해야한다고 알려준다
	(explicit instantiation)
*/


// explicit instantiation
// 빌드할 때 특정 데이터 타입으로 instantiation 해라! 라고 알려주는 것

// template void MyArray<char>::print();
// char type 에 대해서 instatiation 하지 않고 실행하면 여전히 에러

template void MyArray<double>::print();

template class MyArray<char>;
// 클래스 자체를 explicit instantiation 하는 방식