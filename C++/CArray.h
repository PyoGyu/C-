#pragma once

#include <assert.h>
template<typename T>
class CArray
{
private:
	T*	m_Data;
	int		m_CurCount;
	int		m_MaxCount;

public:
	void Push_back(const T& _Data);
	void Reserve(int _Count);
	T& at(int _Idx) { return m_Data[_Idx]; } // 반환 타입을 int* 로도 가능
	T& operator[](int _Idx);
	int Size() { return m_CurCount; }
	int capacit() { return m_MaxCount;  }

	// 아래쪽에 구현된 iterator을 전방선언 해둔다 
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _Other);

public:
	CArray() : m_Data(nullptr), m_CurCount(0), m_MaxCount(0)
	{

	}

	~CArray()
	{
		if (nullptr != m_Data)
			delete(m_Data);
	}

public:
	// inner 클래스(내부클래스)
	// 자신이 선언된 클래스의 private에 접근이 가능하다. (네임스페이스와 차이)
	class iterator
	{
	private:
		// 어떤 멤버를 가지고 있어야, 컨테이너 안에 데이터를 가리키는 역할을 수행할 수 있을까?
		CArray* m_Owner; // iterator 가 가리킬 데이터를 보유하고있는 소유주(컨테이너) 주소값
		int		m_Idx; // 컨테이너가 보유한 데이터중에서 가리킬 인덱스, -1 일경우 end iterator

	public:
		T& operator*();
		void operator++();

		bool operator ==(const iterator& _Other);
		bool operator !=(const iterator& _Other);

	public:
		iterator();
		iterator(CArray* m_Owner, int _Idx);
		~iterator();
	};
};


// 템플릿의 구현부분도 전부 헤더파일에 구현해야 한다. 
template<typename T>
void CArray<T>::Push_back(const T& _Data)
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

template<typename T>
void CArray<T>::Reserve(int _Count)
{
	// reserve 로 확장하는 크기가, 기존 크기 (MaxCount) 보다 커여한다. 
	// assert는 Debug 모드로 실행할때만 동작하고, nullptr 입력시 프로그램 중단
	assert(_Count > m_MaxCount);

	T* pNew = new T[_Count];

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

//template<typename T>
//T& CArray<T>::at(int _Idx)
//{
//	return m_Data[_Idx];
//}

template<typename T>
T& CArray<T>::operator[](int _Idx)
{
	return m_Data[_Idx];
}

//C++ 문법체크
//innerclass를 지칭할때는 반드시 앞에 typename 키워드가 필요하다
template<typename T>
typename CArray<T>::iterator CArray<T>::begin()
{
	iterator iter(this, 0);

	return iter;
}

template<typename T>
typename CArray<T>::iterator CArray<T>::end()
{
	iterator iter(this, -1);

	return iter;
}

template<typename T>
typename CArray<T>::iterator CArray<T>::erase(iterator& _Other)
{
	for (int i = *_Other - 1; i < this->m_CurCount; i++)
	{
		this->m_Data[i] = this->m_Data[i + 1];
	}

	--(this->m_CurCount);

	return _Other;
}

template<typename T>
T& CArray<T>::iterator::operator*()
{
	// end iterator 인 경우 오류
	assert(-1 != m_Idx);

	return m_Owner->m_Data[m_Idx];
}

template<typename T>
void CArray<T>::iterator::operator++()
{
	++m_Idx;

	// 마지막 데이터 개수를 넘어서는 인덱스가 되면, end iterator가 된다. 
	if (m_Owner->m_CurCount <= m_Idx)
	{
		m_Idx = -1;
	}
}

template<typename T>
bool CArray<T>::iterator::operator==(const iterator& _Other)
{
	if (m_Owner == _Other.m_Owner && m_Idx == _Other.m_Idx)
		return true;

	return false;
}

template<typename T>
bool CArray<T>::iterator::operator!=(const iterator& _Other)
{
	if (m_Owner == _Other.m_Owner && m_Idx == _Other.m_Idx)
		return false;

	return true;
}

template<typename T>
CArray<T>::iterator::iterator() : m_Owner(nullptr), m_Idx(-1)
{
}

template<typename T>
CArray<T>::iterator::iterator(CArray* m_Owner, int _Idx) : m_Owner(m_Owner),
m_Idx(_Idx)
{
}

template<typename T>
CArray<T>::iterator::~iterator()
{
}


