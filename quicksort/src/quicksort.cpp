//============================================================================
// Name        : quicksort.cpp
// Author      : MEE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <time.h>
#include <iostream>
using namespace std;

// quicksortttt

void swap(int *var1, int *var2){
		int buf = *var1;
		*var1 = *var2;
		*var2 = buf;
}

void quicksort(int *arr,int start, int end){

	if(start >= end) return;

	int i,j = i = start;
	for (j = start; j < end; j++){
		if(arr[j]<arr[end])
			swap(arr[i++],arr[j]);
	}

	swap(arr[j],arr[i]);

	quicksort(arr,start,i-1);
	quicksort(arr,i+1,j);
}

void print_arr(int *arr, int len){
	for(int i=0;i<len;i++)	
		cout << arr[i] << '\t';

	cout << endl;
}

void fill_arr(int *arr, int len){
	for(int i=0;i<len;i++)
		arr[i] = rand();
}

int main() {
	int arr[100];
	srand(time(NULL));

	fill_arr(arr,100);

	print_arr(arr, 100);

	quicksort(arr,0,99);

	print_arr(arr, 100);

	return 0;
}
