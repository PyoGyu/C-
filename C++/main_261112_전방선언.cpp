
// 전처리기 -> 컴파일 -> 링킹.


typedef long long LL;

// 전방선언
LL Pow(LL _Num, LL _Ex);

void main()
{
	LL value = Pow(2, 10);

}

LL Pow(LL _Num, LL _Ex)
{
	LL value = 1;

	for (LL i = 0; i < _Ex; ++i)
	{
		value *= _Num;
	}

	return value;
}
