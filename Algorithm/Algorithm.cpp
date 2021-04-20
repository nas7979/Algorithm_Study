#include "pch.h"
#include <iostream>
#include <functional>
using namespace std;

template<typename T>
void QuickSort(T* _Array, int _From, int _Length, function<bool(T* _Smaller, T* _Bigger)> _Compare);

int main()
{
	int Array[30];
	for (int i = 0; i < 30; i++)
	{
		Array[i] = rand() % 1000;
	}
	QuickSort<int>(Array, 0, 30, [](int* _S, int * _L)->bool {return *_S <= *_L; });
	for (int i = 0; i < 30; i++)
	{
		printf("%d ", Array[i]);
	}
	system("pause");

	return 0;
}

template<typename T>
void QuickSort(T * _Array, int _From, int _Length, function<bool(T* _Smaller, T* _Bigger)> _Compare)
{
	if (_Length <= 1)
		return;
	int Right, Left;
	int Pivot = _From;
	T Temp;

	while (true)
	{
		Left = _From + 1;
		Right = _From + _Length - 1;
		while (_Compare(&_Array[Left], &_Array[Pivot]))
		{
			if (Left == _From + _Length)
				break;
			Left++;
		}
		while (_Compare(&_Array[Pivot], &_Array[Right]))
		{
			if (Right == _From)
				break;
			Right--;
		}
		if (Left > Right)
			break;

		Temp = _Array[Left];
		_Array[Left] = _Array[Right];
		_Array[Right] = Temp;
	}

	Temp = _Array[Pivot];
	_Array[Pivot] = _Array[Right];
	_Array[Right] = Temp;

	for (int i = _From; i < _From + _Length; i++)
	{
		printf(i == Right ? "(%d) " : "%d ", _Array[i]);
	}
	printf("\n");

	QuickSort(_Array, _From, Right - _From, _Compare);
	QuickSort(_Array, Right + 1, _Length - Right - 1, _Compare);
}
