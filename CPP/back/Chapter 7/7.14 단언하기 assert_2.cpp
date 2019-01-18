int main() {
	const int x = 10;
	
	// assert(x == 5); 
	// 런타임 시 잡아준다
	// #include <cassert>

	static_assert(x == 5, "x should be 5");
	// 컴파일러가 잡아준다
	// const value에만 사용 가능하다.
}