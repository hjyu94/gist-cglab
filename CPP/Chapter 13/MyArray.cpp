#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

/* 
	- ��ŷ ����
	: main.cpp ���� include "MyArray.h"�� �ϸ�
	: ��� ������ main.cpp�� �ִ� ��ó�� �۵��Ѵ�
	: MyArray<char> MyArray�� char ������ Ÿ�Կ� ���ؼ�
	: �ν��Ͻÿ��̼� �ؾ��Ѵٴ� �� ������ �����Ϸ��� �� �� �ִ�
	
	: �׷��� ������,
	: print()��� ��� �Լ��� ������ �Ҷ���
	: MyArray.cpp ���� �������� �ϱ� ������
	: main.cpp������ MyArray.cpp�� include���� �ʴ´�

	: �׷���
	: MyArray.cpp�� �ִ� print() �Լ��� �ν��Ͻÿ��̼��Ҷ�
	: char�� �ؾ��Ѵٴ� ���� �𸣱� ������ ����� ����

	: MyArray��� templatized�� Ŭ������ �ν��Ͻÿ��̼� �� ��
	: � Ÿ������ �ؾ� �ϴ����� 
	: MyArray.h�� ������ �� ���� �� ���� ����.

	[�ذ��]
	1/ #include "MyArray.cpp"�� �ϸ� �ȵȴ�!
	2/ MyArray.cpp ���� print()�� ������ �� ��
	Ư�� ������ Ÿ������ ������ �ؾ��Ѵٰ� �˷��ش�
	(explicit instantiation)
*/


// explicit instantiation
// ������ �� Ư�� ������ Ÿ������ instantiation �ض�! ��� �˷��ִ� ��

// template void MyArray<char>::print();
// char type �� ���ؼ� instatiation ���� �ʰ� �����ϸ� ������ ����

template void MyArray<double>::print();

template class MyArray<char>;
// Ŭ���� ��ü�� explicit instantiation �ϴ� ���