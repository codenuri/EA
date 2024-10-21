#include <type_traits>

// # 핵심 : template 을 만드는 방법

// #1. typename 또는 class 키워드
// => C++98 부터 가능.
//template<typename T>
template<class T>		// 위와 완전히 동일
T square(T a)
{
	return a * a;
}


// #2. auto : C++20 ~ 
// => 아래 코드는 위 코드와 완벽히 동일합니다.
auto square(auto a)
{
	return a * a;
}


// #3. requires clauses : C++20 ~
// => 템플릿 인자에 제약도 전달 가능
template<typename T> requires std::integeral<T>		
T square(T a)
{
	return a * a;
}

// 아래 코드가 위와 동일합니다. - auto 버전에 제약전달 코드. 
auto square(std::integral auto a)
{
	return a * a;
}


int main()
{

}
