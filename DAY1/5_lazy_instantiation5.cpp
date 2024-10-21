#include <iostream>

struct static_member
{
	static_member() { std::cout << "static_member()" << std::endl; }
	~static_member() { std::cout << "~static_member()" << std::endl; }
};
struct instance_member
{
	instance_member() { std::cout << "instance_member()" << std::endl; }
	~instance_member() { std::cout << "~instance_member()" << std::endl; }
};

template<typename T>
struct Object
{
	instance_member m1;
	static static_member m2;
};
// template의 static 멤버 데이타를 외부 선언시에는 아래 처럼(내일 자세히!!)
template<typename T> static_member Object<T>::m2;

// 핵심 : static 멤버 데이타도 사용하지 않으면
//       인스턴스화 되지 않습니다.
//       따라서 생성자 호출 안됨.

int main()
{
//	Object<int>::m2;

	std::cout << "--------" << std::endl;

	Object<int> obj1;
	Object<int> obj2;

	std::cout << "--------" << std::endl;
}


