#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n)
{
    
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;

        if (prev == min(step, n))
            return -1;
    }
    if (arr[prev] == x)
        return prev;

    return -1;
}

int main()
{
    int n,i;
    cout<<"Eneter size of array : ";
    cin>>n;
    cout<<"Enter elements of array"<<endl;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<"Enter key to be searched : ";
    int key;
    cin>>key;
    int index = jumpSearch(a, key, n);
    cout << "\nNumber " << key << " is at index " << index;
    return 0;
}
