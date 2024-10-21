#include <iostream>
#include <functional>
#include <type_traits> // std::type_identity

// # 핵심 : type_identity 개념

// 1. 함수 템플릿은 타입 인자를 생략해도 됩니다.
// 2. 이경우, 컴파일러가 함수 인자를 보고 타입을 추론하게 됩니다.
// 3. 그런데, 컴파일러가 추론하는 것을 막고 싶을때가 있습니다.
//    => 컴파일러의 추론 규칙이 바람직하지 않은 경우

// 4. 이 경우는 아래 기술 사용
template<typename T> struct type_identity 
{
	using type = T;
};

// type_identity<int>::type 은 결국 "?" 타입


template<typename T> void foo(T a)  { }
template<typename T> void goo( typename type_identity<T>::type a)  { }

int main()
{
	foo(10);		// ok
	foo<int>(10);	// ok

	goo(10);	  // ok
	goo<int>(10); // ok
}