#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int x,y;
	    cin>>x>>y;
	    long a[x+1],b[y+1];
	    for(int i=0;i<x;i++)
	    cin>>a[i];
	    for(int i=0;i<y;i++)
	    cin>>b[i];
	    
	    int i=0,j=0;
	    vector<long> vec;
	    while(i<x&&j<y)
	    {
	        if(a[i]<b[j])
	        {
	            vec.push_back(a[i]);
	            i++;
	        }
	        else if(a[i]>b[j])
	        {
	            vec.push_back(b[j]);
	            j++;
	        }
	        else if(a[i]==b[j])
	        {
	            vec.push_back(a[i]);
	            vec.push_back(b[j]);
	            i++;
	            j++;
	        }
        }
        while(i<x)
        {
            vec.push_back(a[i]);
            i++;
        }
        while(j<y){
            vec.push_back(b[j]);
            j++;
        }
        for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
        
        cout<<endl;
	}
	return 0;
}
