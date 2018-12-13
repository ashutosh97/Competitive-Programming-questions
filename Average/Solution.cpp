#include<iostream>
#include<algorithm>
int arr[100000];
using namespace std;
int main()
{
        int n;
        cin>>n;
        for(int h=0;h<n;h++)
        cin>>arr[h];
        sort(arr,arr+n);
        int count=0;
        for(int i=0;i<n;i++)
        {
                if(arr[i]==arr[i-1] || arr[i]==arr[i+1])
                count++;
                else
                {
                        int l=i-1,h=i+1;
                        while(l>=0 && h<n)
                        {
                                int sum=arr[l]+arr[h];
                                if(sum==arr[i]*2)
                                {count++;break;}
                                else if(sum<arr[i]*2)
                                ++h;
                                else
                                --l;
                        }
                }
        }
        cout<<count<<endl;
        return 0;
}
