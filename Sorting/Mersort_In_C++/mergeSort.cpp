
#include "../helper.h"
#include <iostream>
using namespace std;

void copyArr(int from[], int si, int ei, int * to) {
    // while (si <= ei) *to++ = *si++;
    while (si <= ei) {
        *to = from[si];
        ++si;
        ++to;
    }
}


void mergeSortedArray(int arr[], int si, int ei, int mid) {

    int tmp_A[100];
    int tmp_B[100];

    copyArr(arr, si, mid, tmp_A);
    copyArr(arr, mid + 1, ei, tmp_B);

    int i = 0;
    int j = 0;
    int k = si;

    //while a has elements and b has elements, I have to do something
    int size_A = mid - si + 1;
    int size_B = ei - (mid + 1) + 1;

    while (i < size_A && j < size_B) {
        if (tmp_A[i] < tmp_B[j]) {
            arr[k] = tmp_A[i];
            i++;
            k++;
        }
        else {
            arr[k++] = tmp_B[j++];
        }
    }

    while (i < size_A) {
        arr[k++] = tmp_A[i++];
    }

    while (j < size_B) arr[k++] = tmp_B[j++];


}


void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        //no elements
        return;
    }

    int mid = (si + ei) / 2;
    //sort the left part
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);

    mergeSortedArray(arr, si, ei, mid);

}


int main() {
    int arr[100];
    int n;
    cin >> n;
    inputArr(arr, n);

    mergeSort(arr, 0, n - 1);

    printArr(arr, n);
}
