#include <iostream>
#include <ctime>
#include "HSort.h"

using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void Heap(int arr[], int sum)
{
	clock_t t;
	t=clock();
	heapSort(arr, sum);
	t=clock()-t;
	cout << ((double)t)/CLOCKS_PER_SEC;
}
