#include <iostream>

template<typename T>
T square(T a)
{
	std::cout << "T" << std::endl;
	return a * a;
}
// T버전이 있어도, 특정 타입 버전의 함수를 만들수 있습니다.
int square(int a)
{
	std::cout << "int" << std::endl;
	return a * a;
}

int main()
{
	square(3);		// int 버전
	square(3.4);	// T 버전 사용해서, square(double) 함수 생성 

	square<int>(3);	// T 버전 사용. square<int>(int) 함수 생성후 호출.

	square<>(3);	// T 버전 사용, 3을 보고 T=int 로 추론. 
}

// square(int) 와 template 으로 만든 square(int) 의 이름 충돌이 있지 않나요 ?
// => 이름이 다릅니다.
// => godbolt.org 참고