

// 메모리 영역
// 스택 영역 (함수)
// ROM 영역 (코드)
// 데이터 영역
// 힙 영역

int Sub(int _a, int _b)
{
	return _a - _b;
}

// 재귀함수 (Reursion)
// 함수가 자기자신을 다시 호출하는 형태의 함수
// 계층구조(트리) 순환시 구현 용이 
// 재귀함수는 반복문으로 구현하는 함수보다 느리다.
// 함수 호출횟수가 압도적으로 많다.(스택 생성 해제비용 반복발생)
// 종료 조건이 필수 
void Test()
{
	int Arr[10] = {};
	
	Test();
}

// 
int Factorial(int _N)
{
	int value = 1; 

	for (int i = 1; i <= _N; ++i)
	{
		value *= i;
	}

	return value;
}

// !N = N * !(N-1)
int Factorial_Recursion(int _N)
{
	// 만약에 1 팩토리얼을 요청하면 바로 1을 리턴시킨다.
	if (_N == 1)
		return 1;
	

	int value = _N * Factorial_Recursion(_N - 1);
		 
	return value;
}

// Fibonacci 수열
// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
long long Fibonacci(long long _N)
{
	if (_N == 1 || _N == 2)
		return 1;

	long long a = 1;
	long long b = 1;

	for (int i = 2; i< _N; ++i)
	{
		long long temp = b;
		b += a;
		a = temp;
	}

	return b;
}

// F(N) = F(N-1) + F(N-2)
long long Fibonacci_Recursion(long long _N)
{
	if (_N == 1 || _N == 2)
		return 1;

	return Fibonacci_Recursion(_N - 1) + Fibonacci_Recursion(_N - 2);
}

void main()
{
	int Data = Sub(100, 50);

	Data = Factorial(4);

	Data = Factorial_Recursion(2);

	Data = Fibonacci(5);

	//Test();
}





// 내가 exe 파일을 실행하면 해당 파일의 코드들이 코드 영역 ROM에 올라감 거기서 이제 코드를 읽으면서 함수가 나오면 스택에 올리는 느낌
