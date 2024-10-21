#include <iostream>

// # 핵심 : explicit instantiation 
// => 사용(호출)하는 코드가 없어도 함수를 생성해 달라는 것

template<typename T>
T square(T a)
{
	return a * a;
}

// 아래 코드는 
// 사용하지 않더라고 함수를 생성해 달라는 표기법
// => godbolt.org 에서 확인 가능
template int square<int>(int a); 
template double square<>(double a); 
template float  square(float a); 

int main()
{

}

