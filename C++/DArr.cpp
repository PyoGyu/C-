#include "DArr.h"
#include "stdlib.h"
#include <stdio.h>

void Push_Data(DArr* _Array, int _Data)
{
	// 공간이 모자라면, 동적할당해서 추가공간 요청
	if (_Array->CurCount <= _Array->MaxCount)
	{
		if (0 == _Array->MaxCount)
			Reserve(_Array, 2);
		else
			Reserve(_Array, _Array->MaxCount * 2);
	}

	_Array->pData[_Array->CurCount++] = _Data;
}

void Reserve(DArr* _Array, int _Size)
{
	int NextMaxCount = _Size;

	// 동적할당 
	int* pNew = (int*)malloc(sizeof(int) * NextMaxCount);

	// 원래 저장하고 있었던 데이터를 새로운 곳으로 옮겨온다.
	for (int i = 0; i < _Array->CurCount; ++i)
	{
		pNew[i] = _Array->pData[i];
	}

	// 원래 좁았던 공간 해제
	free(_Array->pData);

	// 동적배열 객체가 새로운 공간의 주소를 가르킴
	_Array->pData = pNew;

	// 허용 최대개수 갱신
	_Array->MaxCount = NextMaxCount;
}

void Release(DArr* _Array)
{
	free(_Array->pData);

	_Array->pData = nullptr;
	_Array->CurCount = 0;
	_Array->MaxCount = 0;
}

int GetData(DArr* _Array, int _Idx)
{
	return _Array->pData[_Idx];
}

void Insert(DArr* _DestArr, DArr* _SrcArr, int _InsertIndex, int _BeginIdx, int _EndIdx)
{
	int insertDataCount = (_EndIdx - _BeginIdx + 1);
	int addLength = insertDataCount - (_DestArr->MaxCount - _DestArr->CurCount);

	// a1 길이를 생각해 부족할거 미리 증가 
	if (addLength > 0)
	{
		Reserve(_DestArr, addLength);
	}

	// a1 값 뒤로 들어올 데이터 칸 만큼 밀기
	for (int i = 0; i < insertDataCount; i++)
	{// _DestArr->CurCount+ insertDataCount
		printf("%d. into push Index code ", i);
		_DestArr->pData[_InsertIndex + i + insertDataCount] = _DestArr->pData[_InsertIndex + i];
		printf("%d -> ", _DestArr->pData[2]);
		printf("%d'\n'", _DestArr->pData[_DestArr->CurCount + insertDataCount + i + 1]);

	}

	// a1에 a2 데이터 삽임
	for (int i = 0; i < insertDataCount; i++)
	{
		printf("%d. into insert data code ", i);
		_DestArr->pData[_InsertIndex + i] = _SrcArr->pData[_BeginIdx + i];
		printf("%d'\n'", _SrcArr[_BeginIdx + i]);
	}
}

