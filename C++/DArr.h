#pragma once

// 프로그래머가 직접 만드는 자료형
struct DArr
{
	int* pData; // 힙 영역에 저장된 데이터를 가리킬 포인터
	int CurCount; // 저장한 데이터 개수
	int MaxCount; // 최대 저장개수
};


void Push_Data(DArr* _Array, int _Data);
void Reserve(DArr* _Array, int _Size);
void Release(DArr* _Array);
int GetData(DArr* _Array, int _Idx);

// 과제 
// _DestArr : 목적지 배열
// _SrcArr : 삽입시킬 데이터를 가지고 있는 배열
// _InsertIdx : 삽입 위치, 해당 인덱스가 가리키는 데이터 앞쪽에 삽입
// _BeginIdx, _EndIdx : 삽입시킬 데이터의 시작과 끝 위치
void Insert(DArr* _DestArr, DArr* _SrcArr, int _InsertIndex, int _BeginIdx, int _EndIdx);

// main 호출
//Insert(&a1, &a2, 1, 0, 2);