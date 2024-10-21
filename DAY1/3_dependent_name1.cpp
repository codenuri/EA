// 핵심 : dependent name 의 개념과 typename 키워드

struct Object
{
	using type = int;
	static constexpr int value = 10;
};

template<typename T>
void foo(T obj)
{
	// 아래 코드에서 * 연산자의 의미를 생각해 보세요
	
	// "타입이름::이름" 에서 "이름" 은 
	// 1. 값   일수도 있고
	// 2. 타입 일수도 있습니다
	// => "이름"의 의미에 따라 아래 같은 코드의 * 연산자 의미가 달라집니다.

	Object::value * 10;		// * 는 곱하기 연산자 : 10 * 10
	Object::type  * p1;		// * 는 포인터 연산자 : int* p1 의 의미. 
	

	// 아래 코드를 생각해 보세요
	T::value * 10;
	T::type  * p2;

}


int main()
{
	Object obj;
	foo(obj);
}