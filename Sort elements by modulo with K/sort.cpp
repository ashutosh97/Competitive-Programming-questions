#include <bits/stdc++.h> 
using namespace std; 
  
// Utility function to print the 
// contents of an array 
void printArr(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
// Function to sort the array elements 
// based on their modulo with K 
void sortWithRemainder(int arr[], int n, int k) 
{ 
  
    // Create K empty vectors 
    vector<int> v[k]; 
  
    // Update the vectors such that v[i] 
    // will contain all the elements 
    // that give remainder as i 
    // when divided by k 
    for (int i = 0; i < n; i++) { 
        v[arr[i] % k].push_back(arr[i]); 
    } 
  
    // Sorting all the vectors separately 
    for (int i = 0; i < k; i++) 
        sort(v[i].begin(), v[i].end()); 
  
    // Replacing the elements in arr[] with 
    // the required modulo sorted elements 
    int j = 0; 
    for (int i = 0; i < k; i++) { 
  
        // Add all the elements of the 
        // current vector to the array 
        for (vector<int>::iterator it = v[i].begin(); 
             it != v[i].end(); it++) { 
  
            arr[j] = *it; 
            j++; 
        } 
    } 
  
    // Print the sorted array 
    printArr(arr, n); 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 10, 7, 2, 6, 12, 3, 33, 46 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 4; 
  
    sortWithRemainder(arr, n, k); 
  
    return 0; 
} 
