#include <iostream>
#include <time.h>
using namespace std;
const int arr_len = 2000;
void print(int arr[], int begin, int end);

void CopyArray(int A[], int iBegin, int iEnd, int B[]);
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[]);
void TopDownMergeSort(int A[], int B[], int n);

int main()
{
	srand(time(NULL));
	int arr1[arr_len]{ 0 };
	int arr2[arr_len]{ 0 };

	for (auto& val : arr1)
		val = rand() % 101;

	cout << "Before" << endl;
	print(arr1, 0, arr_len);


	// Merge Sort goes here
    TopDownMergeSort(arr1, arr2, arr_len);

	cout << "After" << endl;
	print(arr1, 0, arr_len);

}

// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int A[], int B[], int n)
{
    CopyArray(A, 0, n, B);           // one time copy of A[] to B[]
    TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

// Sort the given run of array A[] using array B[] as a source.
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
    if (iEnd - iBegin < 2)                       // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin, iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle, iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
    int i = iBegin, j = iMiddle;

    // While there are elements in the left or right runs...
    for (int k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        }
        else {
            B[k] = A[j];
            j = j + 1;
        }
    }
    //print(B, iBegin, iEnd);
}

void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
    for (int k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}


void print(int arr[], int begin, int end)
{
	for (int i = begin; i < end; i++) {
		cout << arr[i];
		if (i < end - 1)
			cout << ", ";
	}			
	cout << endl;
}
