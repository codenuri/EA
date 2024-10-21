#include <tuple>

// # 핵심 : convenient function template
// => C++17 이전에는 클래스 템플릿을 직접 사용하면 타입을 전달해야 하므로
//    사용하는 코드가 복잡해 보입니다.

// 이럴때는 함수 템플릿의 도움을 받으면 됩니다.
template<typename T1, typename T2, typename T3>
std::tuple<T1, T2, T3> make_tuple(const T1& a, const T2& b, const T3& c)
{
	return std::tuple(a, b, c);
}

int main()
{
	std::tuple<int, double, char> t1(10, 3.3, 'A');
		// => 10, 3.3, 'A' 를 보고 타입을 추론할수 있지만
		// => C++17 이전에는 타입 생략이 안되었습니다.

	auto t2 = make_tuple<int, double, char>(10, 3.3, 'A'); // 이 코드가 정확한 표현식이지만
	auto t3 = make_tuple(10, 3.3, 'A');					   // 함수 템플릿은 타입을 생략 할수 
															// 있으므로 std::tuple을
															// 직접 사용하는 것 보다 편리

	// 이미 C++표준에 std::make_tuple 이 있습니다.
	auto t4 = std::make_tuple(10, 3.3, 'A'); // C++14는 이렇께

	// C++17 이후는 아래 처럼 클래스템플릿의 타입인자 생략 가능.
	std::tuple t5(10, 3.3, 'A');
	std::tuple t6{10, 3.3, 'A'};
	auto t7 = std::tuple(10, 3.3, 'A');

	
}