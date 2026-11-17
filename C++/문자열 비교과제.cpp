
// 문자열 우위 비교하기 (순서가 앞인지)
// 값이 작을 수록 우선순위가 높음

// 반환값이 -1 : 왼쪽 문자열이 우선순위가 더 높음
// 반환값이 0 : 두 문자열은 일치함
// 반환값이 1 : 오른쪽 문자열의 우선순위가 더 높음

// 더 앞선 문자가 우선순위가 더 높다(ex a < c)
// "abcd" vs "abcdef"
// 문자가 동일한 경우, 더 짧은 문자열이 우선순위가 더 높다.
int StringLength(char* _Str)
{
	int len = 0;
	while (*(_Str + len) != '\0')
	{
		len++;
	}
	return len;
}

int StrCmp(char* _Left, char* _Right)
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