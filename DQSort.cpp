#include <bits/stdc++.h>
#include <ctime>
#include "DQSort.h"

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Dpartition(int a[], int low, int high, int& i, int& j)
{
	if (high - low <= 1) {
		if (a[high] < a[low])
			swap(&a[high], &a[low]);
		i = low;
		j = high;
		return;
	}

	int mid = low;
	int pivot = a[high];
	while (mid <= high) {
		if (a[mid] < pivot)
			swap(&a[low++], &a[mid++]);
		else if (a[mid] == pivot)
			mid++;
		else if (a[mid] > pivot)
			swap(&a[mid], &a[high--]);
	}

	i = low - 1;
	j = mid; // or high+1
}

void Dquicksort(int a[], int low, int high)
{
	if (low >= high) // 1 or 0 elements
		return;

	int i, j;

	Dpartition(a, low, high, i, j);
	Dquicksort(a, low, i);
	Dquicksort(a, j, high);
}

void Dutchnationalflag(int arr[], int sum)
{		
	clock_t t;
	t=clock();
	Dquicksort(arr, 0, sum-1);
	t=clock()-t;
	cout<<((double)t)/CLOCKS_PER_SEC;
}
