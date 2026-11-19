#include <random>
#include <time.h>


// 정렬 알고리즘
// 오름차순으로 정렬하기 

// 버블소트 이론 (알고리즘 원리) 찾아서 구현해보기
//인접한 두 원소를 비교하여 순서가 맞지 않으면 서로 교환하는 과정을 반복하는 정렬 알고리즘
void BubbleSort(int* _Data, int _Size)
{
	for (int j = 0; j < _Size - 1; ++j)
	{
		bool bSwap = false;

		for (int i = 0; i < _Size - ( j + 1); ++i)
		{			
			// 왼쪽에있는 데이터가 오른쪽보다 큰 경우
			if (_Data[i] > _Data[i + 1])
			{
				bSwap = true;

				int Temp = _Data[i + 1];
				_Data[i + 1] = _Data[i];
				_Data[i] = Temp;
			}
		}

		// 비교 과정에서 스왚이 안 일어났다 == 이미 정렬이 완료됨.
		if (!bSwap)
			break;
	}
}

// insert sort
// 이미 정렬된 앞부분 배열과 현재 선택된 원소(키, Key)를 비교해 알맞은 위치에 끼워 넣어 정렬하는 알고리즘
void InsertSort(int* _Data, int _Size)
{
	for (int i = 1; i < _Size; ++i)
	{
		int key = _Data[i];

		int j = i - 1;

		while (j >= 0 && key < _Data[j])
		{
			_Data[j + 1] = _Data[j];
			--j;
		}

		_Data[j + 1] = key;
	}	
}

// selection sort

// quick sort

int main()
{
	int Arr[10] = {};

	srand(time(nullptr));

	for (int i = 0; i < 10; ++i)
	{
		Arr[i] = rand() % 100 + 1;
	}

	//BubbleSort(Arr, 10);
	InsertSort(Arr, 10);


	return 0;
}