#include <random>
#include <time.h>


// 정렬 알고리즘
// 오름차순으로 정렬하기 

// 버블소트 이론 (알고리즘 원리) 찾아서 구현해보기
//인접한 두 원소를 비교하여 순서가 맞지 않으면 서로 교환하는 과정을 반복하는 정렬 알고리즘
void BubbleSort(int* _Data, int _Size)
{
	int index = 0;
	bool isSwap = true;

	while (true)
	{
		if (index == _Size - 1)
		{
			if (isSwap)
				break;
			else
				isSwap = 1;
			index = 0;
			continue;
		}

		if (*(_Data + index) > *(_Data + index + 1))
		{
			int swapTemp = *(_Data + index);
			*(_Data + index) = *(_Data + index + 1);
			*(_Data + index + 1) = swapTemp;
			
			if(isSwap)
				isSwap = 0;
		}

		index++;
	}
}

// insert sort
// 이미 정렬된 앞부분 배열과 현재 선택된 원소(키, Key)를 비교해 알맞은 위치에 끼워 넣어 정렬하는 알고리즘
void InsertSort(int* _Data, int _Size) 
{
	int key = 1;
	int min = 0;

	for (int j = 1; j < _Size; ++j)
	{
		for (int i = j - 1; i >= 0; --i)
		{
			if (*(_Data + j) < *(_Data + i))
			{
				int temp = *(_Data + j);
				*(_Data + j) = *(_Data + i);
				*(_Data + i) = temp;
			}
		}
	}	
}

// selection sort
void SelectionSort(int* _Data, int _Size)
{
	int Min = 0;

	for (int j = 0; j < _Size; j++)
	{
		for (int i = Min + 1; i < _Size; i++)
		{
			if (*(_Data + Min) > *(_Data + i))
			{
				Min = *(_Data + i);
			}
		}

		int temp = *(_Data);
		*(_Data) = *(_Data + Min);
		*(_Data + Min) = *(_Data);

		Min++;
	}	
}

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
	//InsertSort(Arr, 10);
	SelectionSort(Arr, 10);

	return 0;
}