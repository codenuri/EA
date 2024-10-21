// # 핵심 : typename 과 template 키워드

struct Object
{
	using type = int;				// type 은 "타입"
	static constexpr int value = 10;// value 는 "값"

	template<typename T> struct rebind	// rebind 는 "템플릿"
	{
	};
};

template<typename T>
void foo(T obj)
{
	// 아래 2줄은 dependent name 아님
	// => 컴파일러가 Object 구조체 선언을 조사 가능
	Object::value * 10; // ok
	Object::type  * p1; // ok

	// 아래 2줄은 dependent name!!!
	// => 타입의 의미로 사용되는 것은 typename 필요
	T::value * 10;	// ok. value 는 타입 아님
//	T::type  * p2;	// error. T::type 은 "타입" 이므로 typename 필요
	typename T::type  * p2; // ok


	Object::rebind<int> r1; // ok. r1 는 dependent name 아님

//	T::rebind<int> r2;      // error. 임의의 타입 T 안에 있는
							// rebind 가 무엇인지 알수 없다.
							// "<" 코드를 이해 하지 못하게 된다.

//	T::template rebind<int> r2; // error. typename도 필요

	typename T::template rebind<int> r2;
}




int main()
{
	Object obj;
	foo(obj);
}