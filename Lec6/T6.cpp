#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InsertionSort(int *A, int n);
void MergeSort(int *A, int left, int right);
void Merge(int *A, int left, int center, int right);
void Copy(int *A, int *B, int left, int right);

int main(void) {
	int* A1 = (int*)malloc(sizeof(int)*100000);
	int* A2 = (int*)malloc(sizeof(int)*100000);
	
	for (int i = 0; i < 100000; i++) { // generate random numbers
		A1[i] = rand() % (1000000);
	}
	for (int i = 0; i < 100000; i++) { // copy the array1 to array2
		A2[i] = A1[i];
	}

	clock_t start1 = clock(), diff1;
	InsertionSort(A1, 100000); // call Insertion sort and count time
	diff1 = clock() - start1;
	int msec1 = diff1 * 1000 / CLOCKS_PER_SEC;
	
	clock_t start2 = clock(), diff2;
	MergeSort(A2, 0, 100000 - 1); // call Merge sort and count time
	diff2 = clock() - start2;
	int msec2 = diff2 * 1000 / CLOCKS_PER_SEC;

	printf("Insertion Sort taken %d seconds %d milliseconds\n", msec1/1000, msec1%1000);
	printf("Merge Sort taken %d seconds %d milliseconds\n", msec2/1000, msec2%1000);

	free(A1);
	free(A2);
	return 0;
}

void InsertionSort(int *A, int n) {
	for (int i = 1; i < n; i++){ // for each key item
		int key = A[i];
		int j = i - 1;
		while(j >= 0 && A[j] > key){ // check for each item before the key item
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

void MergeSort(int *A, int left, int right){
	if (left >= right) {
		return;
	}
	if (right - left == 1) { // if there are only two elements in the array
		if (A[left] > A[right]) {
			int tmp = A[left]; // just swap them
			A[left] = A[right];
			A[right] = tmp;
		}
		return;
	}
	int center = (left + right) / 2;
	MergeSort(A, left, center); /*sort left part of the array*/
	MergeSort(A, center + 1, right); /*sort right part of the array*/
	Merge(A, left, center, right);
}

void Merge(int *A, int left, int center, int right){
	int* B = (int*)malloc(sizeof(int)*100000);
	int i1 = left, i2 = center + 1, i3 = left;
	while(i1 <= center && i2 <= right){
		if (A[i1] < A[i2]){ // compare each item in two sub arrays
			B[i3++] = A[i1++]; // place into B
		}else{
			B[i3++] = A[i2++];
		}
	}
	while (i1 <= center){ 
		B[i3++] = A[i1++]; 
	}
	while (i2 <= right){
		B[i3++] = A[i2++];
	}
	Copy(A, B, left, right);
	free(B);
}

void Copy(int *A, int *B, int left, int right) {
	for (int i = left; i <= right; i++) { // copy the whole B array to A
		A[i] = B[i];
	}
}
