int main() {
	const int x = 10;
	
	// assert(x == 5); 
	// ��Ÿ�� �� ����ش�
	// #include <cassert>

	static_assert(x == 5, "x should be 5");
	// �����Ϸ��� ����ش�
	// const value���� ��� �����ϴ�.
}