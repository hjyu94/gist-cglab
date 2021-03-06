컴퓨터가 메모리를 사용하는 방식

/******************************************************************************/
/******************************************************************************/

작성한 프로그램을 컴퓨터에게 실행시켜달라고 얘기하면
운영체제는 메모리를 넘겨준다.
이 메모리를 가지고 이 프로그램을 실행시키세요. 하는 꼴

/******************************************************************************/

메모리는 여러 구역으로 나눠서 사용되는데, 이 구역들을 각각 세그먼트라고 한다.

// 각 세그먼트의 역할
# 코드세그먼트
- 작성한 프로그램이 저장된다
- 메모리에 올라와 있다가, 실행시키는 부분을 가져와서 실행시키게 됨

# 데이터 영역(Initialized data segment)
- globa, static variable
- 초기화가 된 변수들이 저장되는 곳

# BSS 영역
- globa, static variable
- uninitialized data segment
- 0으로 초기화 된 값들이 저장되는 곳

프로그램 자체가 메모리에 자리를 잡아야 되고
그 위에 전역변수가 오래가니까 두번째로 자리를 잡아 있는 것

# Stack 영역
OS는 main 함수를 먼저 실행시킨다
전역 변수가 먼저 자리를 잡고
그 위에 메인함수와 메인 함수의 로컬 변수가 쌓이고
그 위에 main에서 불렀던 함수인 first()와 first함수 내의 로컬 변수가 저장
그 뒤 first()에서 불렀던 second()를 부른다.
second()가 끝나면 위에서부터 차근차근 사라진다.
-> first() 사라지고 -> main() 사라지고 -> 전역변수가 사라진다.

속도가 빠르지만 / 용량이 작다

int main() {
	int array[10000000]; // 이 경우 Stack Overflow.
}

위와 같은 정적 변수는 스택에 저장이 되는데
스택은 용량이 작다는 단점이 있다.
스택을 넘쳐서 오류가 생기게 된다.


# Heap
동적 메모리가 할당 되는 경우 힙에 자리를 잡게 된다.
cf) 지역변수는 스택에 저장되고 빠르지만 용량이 작다
따라서 heap을 추가적으로 사용한다.

/******************************************************************************/

int main() {
	int *ptr = nullptr; // 스택에 *ptr 변수를 저장하고
	ptr = new int[10000000]; 
	// 동적 할당된 변수는 Heap에 저장한다.
	// 이때 힙에 자리잡은 공간을 포인터 변수인 ptr이 가리키게 된다.

	delete[] ptr; 
	// ptr이 가리키고 있는 메모리(힙에 자리를 잡음)가 반납이 됨
	// 그런데 아직 ptr=nullptr이 아니라서
	// ptr을 가지고 작업을 하게 되면 그 곳에 엉뚱한 정보가 있어 오류가 생길 수 있다
}

/******************************************************************************/

void initArray() {
	int *ptr2 = new int[1000];
	// delete[] ptr2;
}

int main() {
	initArray();
	return 0;
}

스택
initArray(), int* ptr2
main()

순서대로 쌓여있다가 initArray() 내에서 동적 메모리를 할당하여 힙에 저장한다.
그런데 initArray()가 끝나면 ptr2가 반납되어 버려서
힙에 메모리는 가지고 있는데 어디에 있는지 알 수가 없어져 사용하지 못하게 된다
주소를 적어놓은 쪽지가 사라져 버린 꼴.

힙 메모리도 쓸데 없는 메모리로 꽉 차면 다른 프로그램이 사용할 메모리가 없어지는 문제
이를 메모리 누수 문제라고 한다.