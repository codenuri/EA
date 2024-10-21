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

type_identity<int>::type n;  // n 은 결국 "int" 타입
						     // 즉, type_identity<T>::type 은 T 타입
							 // int n 하면 되는데, 왜 이렇게 하나요 ??

							// 함수 인자로 사용하기 위해서 만든 것

template<typename T> void foo(T a)  { }
//template<typename T> void goo( typename type_identity<T>::type a)  { }
template<typename T> void goo( typename std::type_identity<T>::type a)  { }

int main()
{
	foo(10);		// ok
	foo<int>(10);	// ok

	goo(10);	  // error. 10 으로 타입을 결정해야 하는데
					// type_identity 가 구조체이고, deduction guide 가 없으므로
					// 추론될수 없다.
					// => 함수 템플릿 만들때 컴파일러에 의한 타입 추론을 막는 기술
					// => C++ 표준에 std::type_identity 가 C++20 부터 제공됩니다.
					// => std::forward<T>(arg) 에서 T 를 생략 할수 없습니다.
					//    즉, 이 기술로 타입추론을 막고 있는 것
	goo<int>(10); // ok
}