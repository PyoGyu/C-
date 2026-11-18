
// 문자열 우위 비교하기 (순서가 앞인지)
// 값이 작을 수록 우선순위가 높음

// 반환값이 -1 : 왼쪽 문자열이 우선순위가 더 높음
// 반환값이 0 : 두 문자열은 일치함
// 반환값이 1 : 오른쪽 문자열의 우선순위가 더 높음

// 더 앞선 문자가 우선순위가 더 높다(ex a < c)
// "abcd" vs "abcdef"
// 문자가 동일한 경우, 더 짧은 문자열이 우선순위가 더 높다.
int StringLength(const char* _Str)
{
	int len = 0;
	while (*(_Str + len) != '\0')
	{
		len++;
	}
	return len;
}

int ExStrCmp(const char* _Left, const char* _Right)
{
	//  1. 양쪽 문자열의 길이를 체크한다.
	int leftLen = StringLength(_Left);
	int rightLen = StringLength(_Right);

	for (int i = 0; i < leftLen; ++i)
	{
		if (_Left[i] < _Right[i])
			return -1;
		else if (_Left[i] > _Right[i])
			return 1;
	}

	if (leftLen < rightLen)
		return -1;
	else if (leftLen > rightLen)
		return 1;
	else
		return 0;
}


int StrCmp(const char* _Left, const char* _Right)
{
	int leftLen = StringLength(_Left);
	int rightLen = StringLength(_Right);

	if (leftLen == 0 && rightLen == 0)
		return 0;
	else if (rightLen == 0)
		return 1;
	else if (leftLen == 0)
		return -1;

	int lenSub = leftLen - rightLen;
	int minStr = 0;

	if (lenSub < 0)
	{
		lenSub = leftLen;
		minStr = -1;
	}		
	else if(lenSub > 0)
	{
		lenSub = rightLen;
		minStr = 1;
	}		
	else
		lenSub = rightLen;

	int indexNum = 0;
	int sub = 0;

	while (1)
	{
		sub = *(_Left + indexNum) - *(_Right + indexNum);

		if (sub > 0)
		{
			return 1;
		}
		else if (sub < 0)
		{
			return -1;
		}
		else
		{
			if (lenSub == indexNum + 1)
			{
				switch (minStr)
				{
				case-1:
					return -1;
					break;
				case 0:
					return 0;
					break;
				case 1:
					return 1;
					break;
				}
			}				

			indexNum++;
		}
	}
		
}

typedef unsigned int UNIT;

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
unsigned int AtoI(const char* _Src)
{
	int arrLen = StringLength(_Src);
	int value = 0;

	for (int i = 0; i < arrLen; ++i)
	{
		value *= 10;

		int temp = _Src[i] % 48;

		value += temp;
	}

	return value;
}

int main()
{
	char szTest1[10] = "abcd";
	char szTest2[10] = "abcdef";

	int value = StrCmp(szTest1, szTest2);

	int Num = 7534;

	char Buff[100] = {};
	ItoA(Num, Buff, 100);

	char Buff1[100] = "7891";
	Num = AtoI(Buff1);

	return 0;
}