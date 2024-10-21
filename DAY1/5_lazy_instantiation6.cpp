// 아래 코드는 에러가 있을까요 ?
template<typename T>
void fn(T value)			// void fn(int value)
{							// {
//	if ( false )			//		if (false)  // 절대 실행되지 않는다.
//		*value = 10;		// 		=> 이 부분의 코드가 인스턴스화 되었을까 ?
							// 		=> if 는 실행시간 제어문. 따라서 컴파일 시간에는
							//		=> 이 부분이 무조건 인스턴스화에 포함된다.
							//		=> "*value = 10" 에서 error.

	if constexpr ( false )	// 컴파일 시간 if 문. 
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
