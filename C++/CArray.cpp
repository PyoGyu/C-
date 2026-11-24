#include "CArray.h"
#include <assert.h> // 디버깅 모드일때 예외처리 걸어 확인

void CArray::Push_back(int _Data)
{
	if (m_Data == nullptr)
	{
		// 최초 4칸 여유공간 확보
		Reserve(4);
	}		
	else if (m_MaxCount <= m_CurCount)
	{
		// 2배씩 공간 증가
		Reserve(m_MaxCount * 2);
	}
		
	//데이터를 힙영역에 저장 및 현재 보유 데이터 개수증가
	m_Data[m_CurCount++] = _Data;

}

void CArray::Reserve(int _Count)
{
	// reserve 로 확장하는 크기가, 기존 크기 (MaxCount) 보다 커여한다. 
	// assert는 Debug 모드로 실행할때만 동작하고, nullptr 입력시 프로그램 중단
	assert(_Count > m_MaxCount);
	
	int* pNew = new int[_Count];

	// 보유하고 있던 데이터를 새로운 공간으로 이동
	for (int i = 0; i < m_CurCount; i++)
	{
		pNew[i] = m_Data[i];
	}
	
	// 메모리 공간에 연속된 데이터가 나열되어 있으므로, 지울때도 delete[]를 사용
	// 기존에 메모리 공간을 해제
	delete[] m_Data;

	// 새로 할당받은 공간을, 데이터를 저장하는 곳으로 지정
	m_Data = pNew;

	// 최대 수용량을 갱신
	m_MaxCount = _Count;
}

int& CArray::at(int _Idx)
{
	return m_Data[_Idx];
}

int& CArray::operator[](int _Idx)
{
	return m_Data[_Idx];
}
