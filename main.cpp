#include <iostream>
#include <ctime>
#include "MSort.h"
#include "LQSort.h"
#include "HQSort.h"
#include "DQSort.h"
#include "HSort.h"

using namespace std;

int main(){
	for(int i=10; i<30; ++i){
		for(int j=0; j<10; ++j){
			int sum=1;
			for(int k=0; k<i; ++k)
				sum*=2;
			int *arr = new int[sum];
			srand(time(NULL)+j);
			for(int k=0; k<sum; ++k){
				arr[k]=rand()%1000;
			}
			cout<<i<<", ,";
			Merge(arr, sum);
			//if(i<=25){
			//	cout<<",lomuto,";
			//	Lomuto(arr, sum);
			//}
			//else
			//	cout<<", , , ";
			//if(i<=29){
			//	cout<<",hoare,";
			//	Hoare(arr, sum);
			//}
			//else
				cout<<", , , , ";
			//cout<<",dutch national flag,";
			//Dutchnationalflag(arr, sum);
			//cout<<",heap,";
			//Heap(arr, sum);
			cout<<"\n";
			delete []arr;
		}
		cout<<"\n";
	}
	return 0;
}
