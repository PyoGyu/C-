

struct MyType
{
	const unsigned int ID;


};


int main()
{	
	// const 와 포인터

	const int i = 100;

	//int* pInt = (int*) & i;
	//*pInt = 200;

	// 주소에 접근에 해석할때 const int 로 해석함
	const int* pInt = &i;
	//*pInt = 200;


	char c = 10;
	char* pC = &c;

	const char cc = 20;
	char* pCC = (char*)&cc;

	const char* pConstChar = &cc;
	//*pConstChar = 30;

	const short s = 0;

	{
		// const 포인터는, 목적지를 const 타입으로 간주하는거지 
		// 포인터 본인이 const(상수화) 가 된게 아니다. 
		// const 포인터가 가리키는 대상이 실제로 const 타입 변수가 아니어도 된다. 
		int Data = 0;
		const int* pTest = nullptr;
		pTest = &Data;
		//*pTest = 200; // 가리키는 곳을 const int로 보는 포인터이기 때문에, 포인터를 이용해서 목적지를 수정 불가능하다.
		Data = 200;

		// 포인터 const 
		// 포인터 변수자체가 const 로 상수화 됨.
		// 초기화 시점에 딱 한번만 주소값을 받을 수 있음
		//int* const pTest1 = nullptr;
		//pTest1 = &Data;;
		int* const pTest1 = &Data;
		*pTest1 = 200;


		const int* const pTest2 = &Data;
	}


	return 0;
}