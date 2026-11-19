#include<stdlib.h>
#include "DArr.h"
#include <stdio.h>

int g_Arr[10];

int main()
{
	{
	//// new - 동적할당 요청
	////malloc();

	////delete - 메모리 해제 요청
	////free();


	//// 일반 배열의 경우, 선언 할 때 개수를 확정해야 한다.
	//int Array[10] = {};

	//// 런타임중에 데이터를 계속 받을 수 있는 배열
	//// 동적 배열, 가변 배열
	//// 데이터를 런타임중에 계속 늘려나갈 수 있다. 

	//
	//DArr array = {};

	//// 40 바이트 동적할당, int* 로 가리켜서 int 단위로 데이터 저장 및 일기
	//array.pData = (int*)malloc(sizeof(int) * 10);
	//array.CurCount = 0;
	//array.MaxCount = 10;

	//// 데이터 추가
	//for (int i = 0; i < 10; ++i)
	//{
	//	array.pData[i] = 10 * (i + 1);
	//	array.CurCount++;
	//}

	//// 현재 동적배열의 저장공간이 다 찼음
	//if (array.CurCount == array.MaxCount)
	//{

	//}

	}

	DArr array = {};
	DArr array1 = {};

	// 미리 10칸의 공간을 확보해둠
	Reserve(&array, 10);

	for (int i = 0; i < 10; i++)
	{
		Push_Data(&array, (i + 1) * 10);
	}

	int Data = GetData(&array, 7);

	// 동적배열 해제
	Release(&array);


	//===== insert Test
	DArr a1 = {};
	DArr a2 = {};

	Push_Data(&a1, 10);
	Push_Data(&a1, 20);
	Push_Data(&a1, 30);

	Push_Data(&a2, 40);
	Push_Data(&a2, 50);
	Push_Data(&a2, 60);

	// 도착 지점, 어디서부터 , 어디를
	Insert(&a1, &a2, 1, 0, 2);

	for (int i = 0; i < a1.MaxCount; i++)
	{
		int data = GetData(&a1, i);
		printf("%d '\n'", data);
	}
	


	return 0;
}