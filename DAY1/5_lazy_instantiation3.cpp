#include <vector>
#include <queue>

// 핵심 : vector 는 앞쪽으로 "삽입/삭제" 할수 없습니다.

/*
class queue
{
	std::vector<int> c;
public:
	void push(int a) { c.push_back(a); } // ok
	void pop() { c.pop_front(); } // error
};
*/
template<typename T>
class queue
{
	std::vector<T> c;
public:
	void push(T a) { c.push_back(a); } // ok
	void pop()     { c.pop_front(); } // 
						// => 인스턴스화가 된 경우만 에러
};

int main()
{
	queue<int> q;

	q.push(10);
//	q.pop(); // 이 코드가 있어야만 에러!!

	// C++ 표준의 std::queue
	// => 내부 컨테이너 변경가능
	// => 단, std::vector는 사용하면 안 됩니다.
	std::queue<int> q1;
	std::queue<int, std::vector<int>> q2;

	q2.pop();

}