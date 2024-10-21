// 템플릿은 틀 입니다.
// 사용한 경우만 인스턴스화 됩니다.
template<typename T> void fn(T value, int)		// A
{
	*value = 10;
}

template<typename T> void fn(T value, double)	// B
{
}

int main()
{
//	fn(1, 3);	// A 가 인스턴스화 됩니다. "*value = 10" 은 때문에 에러

	fn(1, 3.3);	// int, double 이므로 B를 사용하게 됩니다.
				// 1. B를 사용하기로한 결정은 컴파일 시간에 이루어 집니다.
				// 2. 따라서, A는 사용된 적이 없습니다.
				// 3. 인스턴스화 되지 않으므로 "*value = 10" 부분이 컴파일되지 않아서 에러아님.
}
// 함수 오버로딩은 컴파일 시간에 이루어 진다.