#include <stdio.h>
#include <string>
#include <math.h>

typedef unsigned int UNIT;

UNIT Pow(UNIT _num, UNIT _pow)
{
	UNIT value = 1;

	for (int i = 0; i < _pow; ++i)
	{
		value *= _num;
	}
	return value;
}

int StringLength(const char* _Str)
{
	int len = 0;
	while (*(_Str + len) != '\0')
	{
		len++;
	}
	return len;
}

UNIT DigitCount(UNIT _Num)
{
	int value = _Num;
	int DigitCount = 0;

	while (value != 0)
	{
		value /= 10;
		++DigitCount;
	}

	return DigitCount;
}

// 숫자를 문자열로 바꾸기
bool ItoA(UNIT _Num, char* _Dest, int _Size)
{
	// 자릿수

	UNIT DigitCout = DigitCount(_Num);

	// 숫자를 문자열로 옯겨적을 목적지(배열) 의 여유공간이 모자란경우
	if (_Size <= DigitCout)
		return false;

	_Dest[DigitCout] = '\0';

	for (int i = 0; i < DigitCout; ++i)
	{
		UNIT Data = _Num % 10;
		_Num /= 10;

		_Dest[DigitCout - (i + 1)] = Data + 48;
	}

	return true;
} // + 48

// 문자열을 숫자로 바꾸기
//UNIT AtoI(const char* _Src)
//{
//	// 문자열의 길이가 곧 자리수
//	UNIT arrLen = StringLength(_Src);
//	int value = 0;
//
//	for (UNIT i = 0; i < arrLen; ++i)
//	{
//		value *= 10;
//
//		int temp = _Src[i] - 48;
//
//		value += temp;
//	}
//
//	return value;
//}

UNIT AtoI(const char* _Src)
{
	// 문자열의 길이가 곧 자리수
	UNIT arrLen = StringLength(_Src);
	int value = 0;

	for (UNIT i = 0; i < arrLen; ++i)
	{
		value += (_Src[i] - 48) * Pow(10, arrLen - (i + 1));
	}

	return value;
}

int main()
{
	//char szTest1[10] = "abcd";
	//char szTest2[10] = "abcdef";

	//int value = StrCmp(szTest1, szTest2);

	int Num = 7534;

	char Buff[100] = {};
	ItoA(Num, Buff, 100);

	char Buff1[100] = "7891";
	Num = AtoI(Buff1);

	// 위에 문제들이 %d와 하는 역할이 동일
	printf("Hellow %d", 1357);



	// c++ 표준 라이브러리 제공
	// Pow();
	// strcmp();
	// strcat();
	// itoa();
	// atoi();
	// strlen();


	return 0;
}