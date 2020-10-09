#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool binarySearch(vector <int> arr,int ele)
{
	int l=0;
	int r=arr.size()-1;
	while(l<=r)
	{
		int m=(l+r)/2;
		if(arr[m]==ele)
			return true;
		else{
			if(arr[m]<ele)
				l=m+1;
			else r=m-1;
			}
	}
	
	return false;
}

int main()
{               
				vector<int> arr({1,2,3,4,5});
				int ele=1;
				if(binarySearch(arr,ele))
					cout<<"Exists"<<endl;
				else cout<<"Doesn't exist"<<endl;
                return 0;
}
