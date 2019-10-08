#include<bits/stdc++.h>
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	        int sum=0,max=INT_MIN,max1=INT_MIN;
	    for(int i=0;i<n;i++){
	        sum+=a[i];
	        if(sum<a[i])
	            sum=a[i];
	        if(sum>max)
	            max=sum;
	        //if(max<max1)
	          //  sum-=a[i];
	    }
	    cout<<max<<"\n";
	}
	return 0;
}
