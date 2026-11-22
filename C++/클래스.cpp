
#include <vector>

std::vector<int>;


void Add(int _a, int _b) 
{

}

int Add(int _a, float _b) 
{
	return 0; 
}

int Add(int _a, int _b, int _c)
{
	return 0;
}

namespace MY_SPACE
{
	int Sub(int _a, int _b)
	{
		return _a - _b;
	}

	int Gloval = 0;

	int Gloval2 = 0;
}

int Sub(int _a, int _b)
{
	return _a - _b;
}

int Gloval = 0;


// 네임스페이스 제거 (네임스페이스를 안써도 되도록 편의를 봐줌)
//  ㄴ 이 이후부터는 std 네임스페이스 안에 있는 기능에 접근할때 std:: 를 붙이지 않아도 된다.
using namespace std;
//using namespace MY_SPACE;

// 특정 namespace 안에 있는 기능중에 지정한것만 앞에 namespace 붙이지 않아도 되도록 함
using MY_SPACE::Gloval2;



int main()
{

	// namespace
	// 범위지점 연산자 -> :: (스코프라 읽음)
	// 특정 namespace 안에 있는 기능을 언급 가능
	// 같은 이름의 함수, 정의, 변수 등등을 허용하게 하기 위해서, 
	// namespace 가 다르면 완벽하게 같은 함수명 or 변수명 이어도 정의가 가능하다, 구별할 여지가 생기기 때문
	MY_SPACE::Sub(10, 5);
	Sub(20, 10);

	MY_SPACE::Gloval = 100;

	Gloval = 200;

	Gloval2 = 20;

	vector<int>;

	
	// enum




	// 래퍼런스		


	


	// 클래스





	return 0;
}