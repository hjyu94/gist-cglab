#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date {
// access specifier (public, private-default, protected)

private: // ĸ��ȭ. Ŭ���� �ۿ����� ������� ������ �� ����. 
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input) {
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	const int& getDay() {
		return m_day;
	}

	void copyFrom(const Date& original) {
		m_month = original.m_month;
		m_day = original.m_month;
		m_year = original.m_month;
	}
};

int main() {
	Date today{ 8, 4, 2025 };

	/*
		today.m_month = 8; // ��� ����
		// inaccessable (public: �� ����ֱ� ����)
	*/

	Date copy;
	copy.copyFrom(today);

}