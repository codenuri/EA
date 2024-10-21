#include <vector>
#include <list>
// # 핵심 : C++17 "class template type deduction guide" 문법

template<typename T>
class List
{
public:
	List() {}
	List(int sz, const T& value) {}

	// STL 컨테이너 한개를 인자로 가지는 생성자
	template<typename C>
	List(C& c) {}

	template<typename IT>
	List(IT first, IT last) {}
};

// 아래 문법은 C++17 부터 가능.
// 생성자모양 -> List<타입>
List() -> List<int>;

template<typename C>
List(C& c) -> List< typename C::value_type >;

template<typename IT>
//List(IT first, IT last) -> List<반복자IT 가 가리키키는 요소의 타입>
List(IT first, IT last) -> List< typename std::iterator_traits<IT>::value_type >;


int main()
{
	List<int> s1(10, 3); // ok
	List      s2(10, 3); // C++17 부터 ok. 
	List<int> s3;		 // ok
	List      s4; 		 // 디폴트 생성자 자체로는 T 의 추론이 안됨. error
						 // 되도록 하려면 "class template type deduction guide" 제공. 

	std::vector v = { 1,2,3 };
	List s5(v); // 의미를 생각해 보고, 되도록 해보세요

	List s6(v.begin(), v.end());
}

