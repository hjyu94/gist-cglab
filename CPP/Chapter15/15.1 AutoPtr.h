#pragma once

#include <iostream>

// ������ ����� autoptr.h

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
		// �� �κ��� default copy constructor�� �ٸ�
		// Ű�� �Ѱ��ִ� �κ�!
	}

	AutoPtr& operator = (AutoPtr &a)
	{
		if (&a == this) // a = a;
			return *this;

		delete m_ptr; // �̹� ���� ���� ���� �ִٸ� ����������
		m_ptr = a.m_ptr; // ���� ���� �ּҸ� ���� �ǰ�
		a.m_ptr = nullptr; // ���⼭�� �������� �Ű����� �ȴ�.
		return *this;
	}

	// ������ �����ε�
	T& operator *() const { return *m_ptr; }
	T* operator ->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};