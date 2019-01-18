#pragma once

#include <iostream>

// 지금은 사라진 autoptr.h

template<class T>
class AutoPtr
{
public:
	T *m_ptr = nullptr;

public:
	AutoPtr(T *ptr = nullptr)
		: m_ptr(ptr)
	{
	}

	~AutoPtr()
	{
		if (m_ptr != nullptr) delete m_ptr;
	}

	// not copy semantics
	// but move semantics
	AutoPtr(AutoPtr &a)
	{
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; 
		// 이 부분이 default copy constructor와 다름
		// 키를 넘겨주는 부분!
	}

	AutoPtr& operator = (AutoPtr &a)
	{
		if (&a == this) // a = a;
			return *this;

		delete m_ptr; // 이미 내가 뭔가 갖고 있다면 지워버리고
		m_ptr = a.m_ptr; // 새로 들어온 주소를 갖게 되고
		a.m_ptr = nullptr; // 여기서는 소유권이 옮겨지게 된다.
		return *this;
	}

	// 연산자 오버로딩
	T& operator *() const { return *m_ptr; }
	T* operator ->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};