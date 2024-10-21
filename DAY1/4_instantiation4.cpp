#include <vector>

// 핵심 : class template 의 타입 추론은 C++17 부터 사용가능.

template<typename T>
T square(T a)
{
	return a * a;
}

template<typename T>
class List
{
public:
	List(int sz, const T& value) {}
};

int main()
{
	// function template
	// => 함수 템플릿은 타입 인자를 전달해도 되고, 생략도 가능. C++98 ~ 
	square<int>(3);	// ok
	square(3);		// ok

	// class template
	List<int> s1(10, 3); // ok
	List      s2(10, 3); // C++17 부터 가능.
						 // 생성자 인자를 사용해서 타입추론
						 // C++17 이전에는 에러

	std::vector<int> v1 = { 1,2,3 }; // ok
	std::vector      v2 = { 1,2,3 }; // C++17 부터 가능.
}

