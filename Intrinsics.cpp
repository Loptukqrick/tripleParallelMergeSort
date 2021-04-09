#include <cstdlib>
#include "immintrin.h"
#include <chrono>
#include <cstdio>
#include <iostream>;

using namespace std;

void swapVals(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bitonicSort(__m512 *A1i, __m512 *A2i, __m512 *A1o, __m512 *A2o, int indexVal) {
	// A1i and A2i are my 'a' and 'b'
	// A1o and a2o are going to be my L and H that I want to write to memory
	// L1 to L2
	A2i = _mm512_permutexvar_ps(_mm512_set_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15), A2i);

	A1o = _mm512_min_ps(A1i, A2i);
	A2o = _mm512_max_ps(A1i, A2i);

	A1o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(23, 22, 21, 20, 19, 18, 17, 16, 7, 6, 5, 4, 3, 2, 1, 0), A2o);
	A2o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(31, 30, 29, 28, 27, 26, 25, 24, 15, 14, 13, 12, 11, 10, 9, 8), A2o);


	// Storing them as the inputs now so we can do the second round of sorting. L2 to L3
	A1i = _mm512_min_ps(A1o, A2o);
	A2i = _mm512_max_ps(A1o, A2o);

	A2i = _mm512_permutexvar_ps(_mm512_set_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15), A2i);

	A1o = _mm512_min_ps(A1i, A2i);
	A2o = _mm512_max_ps(A1i, A2i);

	A1o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(27, 26, 25, 24, 11, 10, 9, 8, 19, 18, 17, 16, 3, 2, 1, 0), A2o);
	A2o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(31, 30, 29, 28, 15, 14, 13, 12, 23, 22, 21, 20, 7, 6, 5, 4), A2o);


	// L3 to L4
	A1i = _mm512_min_ps(A1o, A2o);
	A2i = _mm512_max_ps(A1o, A2o);

	A2i = _mm512_permutexvar_ps(_mm512_set_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15), A2i);

	A1o = _mm512_min_ps(A1i, A2i);
	A2o = _mm512_max_ps(A1i, A2i);

	A1o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(29, 28, 13, 12, 25, 24, 9, 8, 21, 20, 5, 4, 17, 16, 1, 0), A2o);
	A2o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(31, 30, 15, 14, 27, 26, 11, 10, 23, 22, 7, 6, 19, 18, 3, 2), A2o);


	// L4 to L5
	A1i = _mm512_min_ps(A1o, A2o);
	A2i = _mm512_max_ps(A1o, A2o);

	A2i = _mm512_permutexvar_ps(_mm512_set_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15), A2i);

	A1o = _mm512_min_ps(A1i, A2i);
	A2o = _mm512_max_ps(A1i, A2i);

	A1o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(30, 14,28, 12, 26, 10, 24, 8, 22, 6, 20, 4, 18, 2, 16, 0), A2o);
	A2o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(31, 15, 29, 13, 27, 11, 25, 9, 23, 7, 21, 5, 19, 3, 17, 1), A2o);


	// L5 final sort
	A1i = _mm512_min_ps(A1o, A2o);
	A2i = _mm512_max_ps(A1o, A2o);

	A2i = _mm512_permutexvar_ps(_mm512_set_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15), A2i);

	A1o = _mm512_min_ps(A1i, A2i);
	A2o = _mm512_max_ps(A1i, A2i);

	A1o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(23, 7, 22, 6, 21, 5, 20, 4, 19, 3, 18, 2, 17, 1, 16, 0), A2o);
	A2o = _mm512_permutex2var_ps(A1o, _mm512_set_epi32(31, 15, 30, 14, 29, 13, 28, 12, 27, 11, 26, 10, 25, 9, 24, 8), A2o);

	// Store A1o back into master array
	a[0] = 

	return A2o; // Will be stored back into the array later
}



void selectionSort(int arr[], int startIndex, int endIndex) {
	int i;
	int j;
	int minIndex;

	for (i = startIndex; i < endIndex; i++) {
		minIndex = i;
		for (j = i + 1; j < endIndex + 1; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swapVals(&arr[minIndex], &arr[i]);
	}
}

void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	int blockSize = 16;

	int max = 10000000;
	int *a = (int*)aligned_alloc(64, sizeof(int) * max);
	int *output = (int*)aligned_alloc(64, sizeof(int) * 16);
	for (int i = 0, j = max - 1; i < max; j--) {
		a[i] = j; // the array is filled with descending values: 10000000, 9999999, 9999998, 9999997,...
	}
	
	
	// we just want to pull from the master array like normal, then do the selection sort.
	selectionSort(a, 0, blockSize - 1);
	selectionSort(a, blockSize, 2 * blockSize - 1);

	// This loads the individual array parts into the XMM registers
	__m512 *Ain = _mm512_load_ps(&a[0]); // first 16 integers
	__m512 *Bin = _mm512_load_ps(&a[1]); // second 16 integers
	// ^^^^^ This is what I'm passing into the function
	__m512 *Lout;
	__m512 *Hout;

	int index;

	bitonicSort(Ain, Bin, Lout, Hout, index);



	/////************************This is where you automatically assign vectors rather than manually assign them*************
	//for (int i = 8; i < max; i += 8) {
	//	__m512i second = _mm512_load_si512((__m512i*)&a[i]); // Get the next vector
	//	first = _mm512_max_epi32(first, second);
	//}
	///////*******************************************************************************************************************


	return 0;
}

//Compile with: g++ vector_avx_512_max.cc -o vector_avx_512_max.x -mavx512f