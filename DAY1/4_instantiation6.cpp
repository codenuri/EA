#include <vector>
#include <list>
// # 핵심 : C++17 "class template type deduction guide" 문법

template<typename T>
class List
{
public:
	List() {}
	List(int sz, const T& value) {}
};

// 아래 문법은 C++17 부터 가능.
// 생성자모양 -> List<타입>
List() -> List<int>;

int main()
{
	List<int> s1(10, 3); // ok
	List      s2(10, 3); // C++17 부터 ok. 
	List<int> s3;		 // ok
	List      s4; 		 // 디폴트 생성자 자체로는 T 의 추론이 안됨. error
						 // 되도록 하려면 "class template type deduction guide" 제공. 

//	std::vector v = { 1,2,3 };
//	List s5(v); // ?

//	List s6(v.begin(), v.end());
}

