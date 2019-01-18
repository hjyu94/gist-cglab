#include <iostream>
#include <fstream> // 파일 출력
using namespace std;

class Point
{
private:
	int m_x, m_y, m_z;
public:
	Point() {}

	Point(const int& _x, const int& _y, const int& _z)
		: m_x(_x), m_y(_y), m_z(_z) {}

	void print()
	{
		cout << m_x << ", " << m_y << ", " << m_z << endl;
	}

	// 얘는 멤버 함수로 만들 수 없다
	// 첫번째 파라미터가 포인터가 들어올 수 없기 때문에
	// return 타입이 ostream이기 때문에 연쇄적으로 사용 가능하다.
	// 콘솔, 파일 입출력도 가능하다.
	friend std::ostream& operator << (std::ostream &out, const Point &point) {
		out << point.m_x << ", " << point.m_y << ", " << point.m_z << endl;
		return out; // chaining
	}

	friend std::istream& operator >> (std::istream &in, Point &point) {
		in >> point.m_x >> point.m_y >> point.m_z;
		return in; // chaining
	}
};

int main()
{
	Point p1(0, 1, 2), p2(3, 4, 5);

	p1.print();
	p2.print();

	cout << p1 << p2 << endl;
	cout << endl;

	ofstream of("out.txt"); // 출력할 파일의 이름	
	of << p1 << p2 << endl;
	of.close();

	Point p3, p4;
	cin >> p3 >> p4;
	cout << p3 << p4;
}