#include <iostream>
// 핵심 #1 "template instantiation(템플릿 인스턴스화)" 용어
// => 템플릿(틀) 로 부터 실제 "함수/클래스"를 만드는 과정

// 핵심 #2. instantiation 결과를 확인하는 방법
// => 1. godbolt.org 에서 어셈블리 코드 확인
// => 2. 함수의 이름 출력

// 핵심 #3. Code bloat(코드 폭팔)
// => template 사용시 너무나 많은 함수/클래스가 생성되어서
//    코드메모리가 증가하는 현상
//    메모리가 부족한 환경에서는 주의 !!

#include "fname.h"

template<typename T>
T square(T a)
{
	// __func__ : 함수 이름을 담은 표준 매크로
	//		      함수 인자를 제외한 함수 이름만 출력

	// __FUNCSIG__ : 함수 이름 + 인자 (단, visual studio 전용)
	// __PRETTY_FUNCTION__ : 함수 이름 + 인자 ( g++ 전용)

//	std::cout << __func__ << std::endl;
//	std::cout << __FUNCSIG__ << std::endl;
//	std::cout << __PRETTY_FUNCTION__ << std::endl;

	// _FNAME_ : fname.h 에 있는 매크로!!!
	//			이번주 강의에서 많이 사용
	std::cout << _FNAME_ << std::endl;
	
	return a * a;
}

int main()
{
	square<int>(3);			
	square<double>(3.3);
	square(3);
}

