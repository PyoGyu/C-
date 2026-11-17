
// 문자열은 끝에 null 문자가 있어야 한다. (어디까지가 문자인지 표시하는 마침표)

// 함수
int StrLength(char* _Str)
{
	int i = 0;
	while (_Str[i] != '\0') { ++i; }
	return i;
}

bool strCat(char* _Dest, int _Size, char* _Src)
{
	// 문자열 길이 체크
	int DsetLen = StrLength(_Dest);	
	int SrcLen = StrLength(_Src);

	// 이어붙일 공간이 모자람 체크
	if (DsetLen + SrcLen >= _Size)
		return false;

	for (int i = 0; i < SrcLen; ++i)
	{
		_Dest[DsetLen + i] = _Src[i];
	}

	return true;

	// 1. 반환타입을 이용해서 문자열 이어 붙이기가 성공했는지 실패했는지 반환할것

	// 2. _Size 는 _Dest 가 가리키는 문자열의 최대 여유공간을 입력받는 용도
	/*int count = 0;

	for (int i = 0; i < 10; ++i)
	{		
		if (*(_Dest + i) == 0)
		{
			*(_Dest + i) = *(_Src + count++);
		}		
	}	

	if (count < 3)
		return false;
	else
		return true;*/
}

int main()
{
	// 문자 - 아스키코드
	char c = 0;
	
	// 문자 전용 2Byte 정수타입 자료형 wchar_t
	wchar_t wc = 0; 


	c = 101;
	wc = 101;

	// 문자열 - 문자가 연속된 메모리 공간에 나열되어있음
	c = 'f';

	//char szBuff[5] = { 97, 98, 99, 100, 101 }; // = { 'a', 'b', 'c', 'd', 'e'}
	char szBuff[5] = "abcd";

	// 2 바이트 단위 문자를 표현할때는 앞에 L을 붙여준다. 
	wc = L'a';
	wchar_t szWBuff[5] = L"abcd"; 
	// 값에 L을 붙여 2바이트 문자 전용 wchar 타입임을 표기
	

	// 문자열 이어붙이기

	char szTest[10] = "abcd";

	char szTest2[10] = "efgh";

	strCat(szTest, 10, szTest2);


	return 0;
}