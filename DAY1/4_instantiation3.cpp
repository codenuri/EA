#include <iostream>
#include "square.h"	

// # 핵심 : template 과 파일 분할, explicit instantiation

// 1. template 은 구현 자체가 모두
//    헤더에 있어야 합니다.

// 2. 이유는 사용할때 함수를 생성하라면
//    헤더 안에 모든 구현이 있어야 생성가능


// 3. 단, .cpp 쪽에 명시적 인스턴스화를 사용하면 됩니다.
// => square.cpp 참고
// => 단, 이경우, int, double 외의 버전을 사용하면
//    컴파일 에러 입니다.

// square.h square.cpp 소스 참고

int main()
{
	square(3);
	square(3.3);
	square(3.3f); // error. 
}

