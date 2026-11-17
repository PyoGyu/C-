
typedef unsigned char Byte;

void MemCpy(void* _Dest, void* _Src, int _size);



// 포인터
int main()
{
	int I = 0;
	int* pI = &I;

	char c = 0;
	pI = (int*) & c; // 강제 형변환을 이용해서 문법 오류를 우회함

	//*pI = 100;

	{
		int* pTest = nullptr;

		char Arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		pTest = (int*)Arr;

		char Data = *((char*)(pTest + 1)); // 5
	}

	int Src = 2000;

	int Dest = 0;

	// 무엇이든 복사 가능해야 함
	MemCpy(&Dest, &Src, sizeof(int));


	short arrDst[20] = {};

	for (int i = 0; i < 10; ++i)
	{
		arrDst[i] = i + 1;
	}

	short arrSrc[5] = { 10, 20, 30, 40, 50 };

	// arrDst 11번째 부터 arrSrc에 있는 값을 이어붙이기

	short* pSdst = arrDst;
	short* pSsrc = arrSrc;

	for (int i = 0; i < 5; ++i)
	{
		*(pSdst + 10 + i) = *(pSsrc + i);
	}


	return 0;
}

void MemCpy(void* _Dest, void* _Src, int _size)
{
	for (int i = 0; i < _size; ++i)
	{
		*(((Byte*)_Dest + i)) = *(((Byte*)_Src + i));
	}
	
}