#include <bits/stdc++.h>
#include <ctime>
#include "LQSort.h"

using namespace std;

int Lpartition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void LquickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = Lpartition(arr, low, high);
		LquickSort(arr, low, pi - 1);
		LquickSort(arr, pi + 1, high);
	}
}

void Lomuto(int arr[], int sum)
{
	clock_t t;
	t=clock();
	LquickSort(arr, 0, sum-1);
	t=clock()-t;
	cout<<((double)t)/CLOCKS_PER_SEC;
}

