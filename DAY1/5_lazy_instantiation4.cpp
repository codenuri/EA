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

struct Object
{
	instance_member m1;
	static static_member m2;
};
static_member Object::m2;

// 핵심 1. static 멤버 데이타는 객체가 없어도 메모리에 생성됩니다.
// => Object 객체를 한개도 생성하지 않아도 m2 는 메모리에 존재 합니다.
// => m2 생성자가 호출된다는 것

// 핵심 2. instance 멤버는 객체를 생성해야만 메모리에 존재
int main()
{
	std::cout << "--------" << std::endl;

	Object obj1;
	Object obj2;

	std::cout << "--------" << std::endl;
}
// 				// Object::m2의 생성자는 최초 1회 호출
// Object obj1;  // obj1 에 대해서 생성자 호출
// Object obj2;  // obj2 에 대해서 생성자 호출
//				// 즉, 생성자는 객체당 한번씩 호출

