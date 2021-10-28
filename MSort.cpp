#include <iostream>
#include <ctime>
#include <vector>
#include "MSort.h"

const int Max = 1000;
using namespace std;

void Merge1(vector<int> &Array, int front, int mid, int end){

	vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
		RightSub(Array.begin()+mid+1, Array.begin()+end+1);

	LeftSub.insert(LeftSub.end(), Max);      // 在LeftSub[]尾端加入值為 Max 的元素
	RightSub.insert(RightSub.end(), Max);    // 在RightSub[]尾端加入值為 Max 的元素

	int idxLeft = 0, idxRight = 0;

	for (int i = front; i <= end; i++) {

		if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
			Array[i] = LeftSub[idxLeft];
			idxLeft++;
		}
		else{
			Array[i] = RightSub[idxRight];
			idxRight++;
		}
	}
}

void MergeSort(vector<int> &array, int front, int end){
	if (front < end) {                	 // 表示目前的矩陣範圍是有效的
		int mid = (front+end)/2;         // mid即是將矩陣對半分的index
		MergeSort(array, front, mid);    // 繼續divide矩陣的前半段subarray
		MergeSort(array, mid+1, end);    // 繼續divide矩陣的後半段subarray
		Merge1(array, front, mid, end);  // 將兩個subarray做比較, 並合併出排序後的矩陣
	}
}

void Merge(int arr[], int sum) {

	vector<int> array;
	for(int i=0; i<sum; ++i){
		array.push_back(arr[i]);
		//	    cout<<arr[i]<<"\n";
	}
	clock_t t;
	t = clock();
	MergeSort(array, 0, array.size()-1);
	t = clock() - t;
	cout<<((long double)t)/CLOCKS_PER_SEC;

}
