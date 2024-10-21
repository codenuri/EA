// lazy1 은 에러인데, 아래 코드는 왜 에러가 아닐까요 ?
// lazy instantiation
// => 사용된 (멤버함수)템플릿만 인스턴스화가 된다.
template<typename T>
class Object
{
	T value;
public:
	void mf()
	{
		*value = 10; 
	}
};

int main()
{
	Object<int> obj;
	obj.mf();	// 이렇게 사용한 경우만 인스턴스화에 포함 됩니다.
}
