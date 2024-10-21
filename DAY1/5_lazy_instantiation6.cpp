// #ifdef : 전처리기가 처리 합니다. 
//          전처리 과정에서 코드의 포함/제외 여부를 결정
//  		컴파일러의 기능을 사용할수 없습니다

// if constexpr : 컴파일 시간에 코드의 포함/제외(인스턴스화) 여부를 결정
//				  컴파일러의 모든 능력 사용
//				  C++17 부터 사용가능. 

template<typename T>
void foo(T a)
{
#ifdef "T 가포인터인지 조사" => 이걸 하려면 컴파일러의 능력이 필요 합니다.
	// 포인터 알고리즘
#else 
	// 포인터가 아닌 알고리즘
#endif
}

// 아래 코드는 에러가 있을까요 ?
template<typename T>
void fn(T value)			// void fn(int value)
{							// {
//	if ( false )			//		if (false)  // 절대 실행되지 않는다.
//		*value = 10;		// 		=> 이 부분의 코드가 인스턴스화 되었을까 ?
							// 		=> if 는 실행시간 제어문. 따라서 컴파일 시간에는
							//		=> 이 부분이 무조건 인스턴스화에 포함된다.
							//		=> "*value = 10" 에서 error.

	if constexpr ( false )	// 컴파일 시간 if 문 ( C++17)
		*value = 10;		// => ( ) 안에는 컴파일 시간에 계산 가능한것만 올수 있다.
							// => 조건이 false 라면 인스턴스화에 포함 안함.


	// 활용
	if constxpr( T가 정수 일때 )
		// 정수에 최적화된 알고리즘

	else if constxpr( T가 실수 일때 )
		// 실수에 최적화된 알고리즘

	else if constxpr( T가 포인터 일때 )
		// 포인터에 최적화된 알고리즘

}


int main()
{
	int n = 10;
	fn(n);
}
