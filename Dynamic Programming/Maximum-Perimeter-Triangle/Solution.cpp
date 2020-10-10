#include <bits/stdc++.h>

using namespace std;

int main()
{
    int index1,index2,index3;
    long int input,perimeter,perimax=0;
    cin>>input;
    long int arr[input];
    for(int i=0;i<input;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+input);
    for(int i=input-1;i>=2;i--)
    {
        if(arr[i-2]+arr[i-1]>arr[i] )
        {
            
            perimeter=arr[i-2]+arr[i-1]+arr[i];
            if(perimeter>perimax)
            {
            index1=arr[i-2];
            index2=arr[i-1];
            index3=arr[i];
            perimax=perimeter;
                
            }
            
        }
    }
    
    
    if(perimax>0)
    {
        cout<<index1<<" "<<index2<<" "<<index3;
    }
    else
        cout<<"-1";
}
