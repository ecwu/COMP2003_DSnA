#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Median_three(int *A, int left, int right) {
	int temp = 0;
	if (A[left] > A[(right + left) / 2]) {
		temp = A[left];
		A[left] = A[(right + left) / 2];
		A[(right + left) / 2] = temp;
	}
	// check for the left and middle element
	if (A[(right + left) / 2] > A[right]) {
		temp = A[right];
		A[right] = A[(right + left) / 2];
		A[(right + left) / 2] = temp;
	}
	// check for the middle and right element
	if (A[left] > A[(right + left) / 2]) {
		temp = A[left];
		A[left] = A[(right + left) / 2];
		A[(right + left) / 2] = temp;
	}
	// check for the left and middle element
	// now those three elements are in the correct order

	// let the center element be the Median of three
	temp = A[(right + left) / 2];
	A[(right + left) / 2] = A[right - 1];
	A[right - 1] = temp;
	// swap the miidle and right - 1 element and ready to sort
	return;
}

int Partition(int *A, int left, int right) {
	int temp = 0;
	Median_three(A, left, right);
	// swap A[p] and A[right]
	int i = left + 1, j = right - 2, pivot = A[right - 1];
	while (true) {
		// find the swap items
		while (A[i] < pivot) {
			i++;
		}
		while (A[j] > pivot) {
			j--;
		}
		if (i < j) {
			if (A[i] == pivot && A[j] == pivot) {
				// if the i j are equals to pivot, move on
				i++;
				j--;
			}
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			// swap A[i] and A[j]
		}
		else {
			break;
		}
	}
	temp = A[i];
	A[i] = A[right - 1];
	A[right - 1] = temp;
	// swap A[i] and A[right - 1]
	return i;
}

void QuickSort(int *A, int left, int right) {
	int p = 0;
	//If the partition only have 1 elemenet
	if (left >= right) {
		return;
	}
	//If the partition only have 2 elemenets
	if (left + 1 == right) {
		if (A[left] > A[right]) {
			int temp = A[left];
			A[left] = A[right];
			A[right] = temp;
		}
		return;
	}
	p = Partition(A, left, right);
	QuickSort(A, left, p - 1); // Partition for left part
	QuickSort(A, p + 1, right); // Partition for right part
}

void Insert(int *A, int *size, int x) {
	int hole = (*size)++;
	int parent;
	while (hole > 0) {
		parent = (hole - 1) / 2; // find the parent node position
		if (A[parent] >= x) { // parent is greater than the x
			break; // do nothing
		}
		A[hole] = A[parent]; // swap the hole and parent
		hole = parent;
	}
	A[hole] = x; // place the x to the correct position (hole)
}

void DelectMax(int *A, int *size) {
	int min = A[--(*size)];
	A[*size] = A[0]; // swap the minium element with the hole
	int hole = 0, children;
	while (hole < *size) { // if there are still element(s) in the heap
		if (hole * 2 + 2 >= *size) {
			if (hole * 2 + 1 >= *size)
				break;
			if (A[hole * 2 + 1] > min) { // if the hole's left children is greater than min
				A[hole] = A[hole * 2 + 1];
				hole = hole * 2 + 1; // swap
			}
			break;
		}
		if (min >= A[hole * 2 + 1] && min >= A[hole * 2 + 2])
			break;
		if (A[hole * 2 + 1] < A[hole * 2 + 2]) { // decide which size the min should go
			children = hole * 2 + 2;
		}
		else {
			children = hole * 2 + 1;
		}
		A[hole] = A[children];
		hole = children;
	}
	A[hole] = min; // place the min to the hole
}

void HeapSort(int *A, int n) {
	int size = 0; // heap size
	for (int i = 0; i < n; i++) { // add every elements to the heap
		Insert(A, &size, A[i]);
	}
	for (int i = n - 1; i >= 0; i--) { // remove the toppest element
		DelectMax(A, &size);
	}
}


int main(void) {
	int* A1 = (int*)malloc(sizeof(int) * 100000);
	int* A2 = (int*)malloc(sizeof(int) * 100000);

	for (int i = 0; i < 100000; i++) { // generate random numbers
		A1[i] = rand() % (1000000);
	}
	for (int i = 0; i < 100000; i++) { // copy the array1 to array2
		A2[i] = A1[i];
	}

	clock_t start1 = clock(), diff1;
	QuickSort(A1, 0, 99999); // call Quick sort and count time
	diff1 = clock() - start1;
	int msec1 = diff1 * 1000 / CLOCKS_PER_SEC;

	clock_t start2 = clock(), diff2;
	HeapSort(A2, 100000); // call Heap sort and count time
	diff2 = clock() - start2;
	int msec2 = diff2 * 1000 / CLOCKS_PER_SEC;

	printf("QuickSort taken %d seconds %d milliseconds\n", msec1 / 1000, msec1 % 1000);
	printf("HeapSort taken %d seconds %d milliseconds\n", msec2 / 1000, msec2 % 1000);

	free(A1);
	free(A2);
	return 0;
}
