/* C++ Solution */

#include <bits/stdc++.h>
using namespace std;

/*Function to check whether zero sum subarray exists or not*/
bool hasZeroSum(int arr[], int N)
{
    set<int> st;
    int sum=0;
    for(int i=0;i<N;i++)
    {
        sum+=arr[i];
        /*if Set contains a sum already,
        that means zero sum subArray exists*/
        if(st.find(sum)!=st.end()||sum==0)
        return true;
        
        st.insert(sum);
    }
    return false;
}

int main() {
	int N;
	cin>>N;
	int arr[N+1];
	
	//Array input
	for(int i=0;i<N;i++)
	    cin>>arr[i];
	
	
	bool ans = hasZeroSum(arr,N);
	cout<<ans;
	return 0;
}
