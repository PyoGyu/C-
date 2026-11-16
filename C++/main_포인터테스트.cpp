


int main()
{
	int a = 10;
	int b = 0;

	int* p = 0;
	int* p1 = 0;

	p = &a;
	p1 = &b;

	*p1 = *p; // b = a;


	int Test[10] = { 1,2, 3,4,5,6,7,8,9, 10 };

	int Other[10] = {};

	int* pStart = &Test[0];
	// int* pStart = Test; 배열 이름이 배열의 첫 주소니까 동일한 코드임 

	// 반복문을 이용하여 Test의 내용을 Other로 옮겨봐라

	for (int i = 0; i < 10; ++i)
	{
		Other[i] = *(pStart + i);
		// Other[i] = pStart[i];
	}

	for (int i = 0; i < 10; ++i)
	{
		pStart = &Test[i];

		Other[i] = *pStart;
	}


	// 포인터 선언 시, 앞에 붙이는 자료형의 의미
	void* pVoid = 0;

	int i = 0;
	char c = 0;

	int* pInt = &i;
	//int* pInt = &c; 오류

	pVoid = &i;
	pVoid = &c;

	//*pVoid; 오류

	// 일반적인 포인터(void 제외) 들은 선언 당시 설정한 자료형의 변수의 주소만 받을 수 있다. 
	// 포인터 변수는 선언 시점에서, 목적지를 어떻게 해석할지 미리 정해두기 때문에

	// void* 의 경우 어떤 자료형 변수의 주소라도 다 받을 수 있다. 
	// 자신이 가리키는 대상을 해석(분석) 하지 않는다. 
	// 포인터 연산으로 역참조 불가능


	return 0;
}