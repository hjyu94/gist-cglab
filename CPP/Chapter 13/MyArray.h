#pragma once
#include <assert.h> // for assert()
#include <iostream>

/*
	둘 다 가능.
	template<typename T>;
	template<class T>;
*/

template<typename T> // T: type에 대한 매개변수
class MyArray
{
private:
	int m_length;
	T *m_data; // int, double, float, char, ...

public:
	MyArray()
	{
		m_length = 0;
		m_data = nullptr;
	}
	MyArray(int length)
	{
		m_length = length;
		m_data = new T[length]; 
	}
	~MyArray()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	T & operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	int getLength()
	{
		return m_length;
	}
	void print();
};

/*
	void MyArray::print()
	{
		for (int i = 0; i < m_length; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	} 가 아니라, 아래 처럼 써야 하며
*/

/*
	template<typename T>
	void MyArray<T>::print()
	{
		for (int i = 0; i < m_length; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	얘를 MyArray.cpp로 옮긴다면?
*/