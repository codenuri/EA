template<typename T>
struct Object
{
	using type = int;

	// 앞에 rebind 는 "타입 템플릿"
	// 아래 mf 는 "함수 템플릿"
	template<typename U>
	static void mf() {	}
};

template<typename T>
void foo()
{
	// 아래 2개는 모두 dependent name
//	T::type t1;
//	Object<T>::type t1;

	// 1. typename 
//	Object<int>::type t1;   // ok. T에 의존 안함. dependent name 아님
//	Object<T>::type t2;		// error. dependent name 이므로 typename 필요
	typename Object<T>::type t2;
	
	
	// 2. template
	Object<int>::mf<double>();	// ok
//	Object<T>::mf<double>();	// error. mf 는 dependent name 이므로 < 해석 안됨

	Object<T>::template mf<double>(); // ok. mf 는 template 이라고 알리는 것
									// 이때는 mf 는 타입은 아니므로
									// typename 은 필요 없음

	Object<int> o1;	// o1 은 dependent name  아님
	Object<T>   o2;	// o2 는 dependent name

	o1.mf<double>();	// ok
//	o2.mf<double>();	// error	
	o2.template mf<double>();	// ok	이표현이 정확한 표기법
								// 하지만 일부 컴파일러는 위 코드도 허용
}

int main()
{
	foo<int>();
}