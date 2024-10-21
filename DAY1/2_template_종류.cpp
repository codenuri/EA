#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <funtional>

// # 핵심 : template 의 종류 
// => 5개 가지 종류의 템플릿이 있음.

// 1. function template ( C++98 ~ )
template<typename T> T square(T a)
{
	return a * a;
}

// 2. class template ( C++98 ~ )
template<typename T> class Vector
{
	T* buff;
};

// 3. variable(변수) template - C++14    
// => 주의!! variadic 이 아닌 variable
template<typename T>
constexpr T pi = static_cast<T>(3.141692);

double d = pi<double>;	
float f = pi<float>;	


// 4. using template - C++11
template<typename T>
using MyList = std::list<T>;

MyList<int> s; 


// 5. concept template - C++20
template<typename T>
concept Container = requires(T& c)
{
	std::begin(c);
	std::end(c);
};