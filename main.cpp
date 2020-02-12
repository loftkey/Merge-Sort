
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& A, int start, int mid, int end);
void merge_sort(vector<int>& A, int start, int end);
void merge_sort_helper(vector<int>& A);

int main() {

    vector<int> scores;
    scores.push_back(73);
    scores.push_back(42);
    scores.push_back(85);
    scores.push_back(90);
    scores.push_back(64);
    scores.push_back(100);
    scores.push_back(56);
    scores.push_back(78);

    cout << "Before: " << endl;
    for (int i = 0; i < scores.size(); i++)
        cout << scores[i] << endl;

    
    //merge_sort(scores, 0, 7);
    merge_sort_helper(scores);


    cout << endl <<  "After: " << endl;
    for (int i = 0; i < scores.size(); i++)
        cout << scores[i] << endl;

    return 0;
}

void merge(vector<int> &A, int start, int mid, int end) {
    //stores the starting position of both parts in temporary variables.
    int p = start, q = mid + 1;

    vector<int> Arr(end - start + 1);
    int k = 0;

    for (int i = start; i <= end; i++) {
        if (p > mid)      //checks if first part comes to an end or not .
            Arr[k++] = A[q++];

        else if (q > end)   //checks if second part comes to an end or not
            Arr[k++] = A[p++];

        else if (A[p] < A[q])     //checks which part has smaller element.
            Arr[k++] = A[p++];

        else
            Arr[k++] = A[q++];
    }
    for (int p = 0; p < k; p++) {
        /* Now the real array has elements in sorted manner including both
             parts.*/
        A[start++] = Arr[p];
    }
}

void merge_sort(vector<int> &A, int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;           // defines the current array in 2 parts .
        merge_sort(A, start, mid);                 // sort the 1st part of array .
        merge_sort(A, mid + 1, end);              // sort the 2nd part of array.

      // merge the both parts by comparing elements of both the parts.
        merge(A, start, mid, end);
    }
}

void merge_sort_helper(vector<int>& A)
{
    merge_sort(A, 0, A.size() - 1);
}