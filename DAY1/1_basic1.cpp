// # 핵심 : template 기본 개념

// 함수 오버로딩 : 인자의 갯수나 타입이 다르면 동일이름의 함수를 여러개 만들수 있다.
/*
int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}
*/
// 구현이 동일(유사)한 함수가 여러개 필요하면
// 함수를 만들지 말고, 틀(템플릿)을 만들자.

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	square<int>(3);		// 1. int square(int a) 함수 를 컴파일 시간에 생성하고
						// 2. 이 위치에는 "call square<int>(3)" 의 기계어 생성

	square<double>(3.3);// double square(double a) 함수 생성.

	// 타입 인자는 생략가능
	square(3);  // T=int 로 추론.. 
}














// C++ Template Programming

// 강석민 강사 
// smkang @ codenuri.co.kr 

// github.com/codenuri/ea/DAY1.zip 받아서 압축 풀면 됩니다.
// => 수업시간에 변경한 소스도 이곳에 올려 놓겠습니다.

// 실습 환경
// => 표준 C++ 언어를 컴파일할수 있는 어떠한 컴파일러도 가능
// => 권장 : "g++14.x" 
//           "clang++ 18.x"
//           "visual studio 2022"

// 강사는 "g++15.0" 과 "visual studio 2022 preview" 사용

// 주요 내용 : C++ template 문법과 다양한 테크닉
// => C++98 ~ C++20/23 까지.. 
// 1일차 : 비교적 쉬운 내용.
// 2일차 ~ : 복잡한 다양한 내용들
