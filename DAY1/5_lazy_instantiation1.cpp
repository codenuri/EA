// # 핵심 : lazy instantiation 개념

// 아래 코드에서 ? 가 왜 에러인지 생각해 보세요.
class Object
{
	int value;
public:
	void mf()
	{
		*value = 10; // error. int 타입을 * 할수 없다.
	}
};

int main()
{
	Object obj;
}
