#include <iostream>

// # 핵심 : square vs square<int>

// square      : 함수가 아닌 함수를 만드는 틀(template) 입니다.
// square<int> : 함수!!. square 틀을  가지고 생성된 함수

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	printf("%p\n", &square);	// error. square 는 함수 가 아닌 함수를 만드는 틀
								// 컴파일 시간에 컴파일러가 사용.


	printf("%p\n", &square<int> ); // ok 

	auto p1 = &square;			// error
}

