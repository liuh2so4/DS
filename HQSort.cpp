#include <bits/stdc++.h>
#include <ctime>
#include "HQSort.h"

using namespace std;

int Hpartition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (true) {
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}

void HquickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = Hpartition(arr, low, high);
		HquickSort(arr, low, pi);
		HquickSort(arr, pi + 1, high);
	}
}

void Hoare(int arr[], int sum)
{		
	clock_t t;
	t=clock();
	HquickSort(arr, 0, sum-1);
	t=clock()-t;
	cout<<((double)t)/CLOCKS_PER_SEC;
}

