// lazy1 은 에러인데, 아래 코드는 왜 에러가 아닐까요 ?
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
}
