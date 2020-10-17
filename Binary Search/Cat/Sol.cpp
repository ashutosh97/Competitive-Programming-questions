#include<bits/stdc++.h>
using namespace std;
vector<long long int> v;
long long int l=0,r=0,mid,big;
int unpair;
long long int data[2000009];
int main()
{
	int n;
	scanf(" %d",&n);
	long long int a;
	for(int i=0;i<n;i++)
	{
		scanf(" %lld",&a);
		v.push_back(a);
		l=min(l,a);
		r=max(r,a);
		data[i]=a;
		if(i%2==1)
		{
			//if the cat that stay in odd array has not the same value of the left cat then it is not in pair.
			if(unpair==0)
			{
				if(a!=data[i-1]) 
				{
					unpair=1;
				}
			}
		}
	}
	//In the case that every cat stay in pair.
	if(unpair==0)
	{
		printf("0");
		return 0;
	}
	sort(data,data+n);
	r=n-1;
	mid=(l+r)/2;
	int broke=0;
	//B Search for the size of pocket.
	while(1)
	{
		if(l==r) break;
		for(int i=0;i<n;i++)
		{
			//If the cat is bigger than the pocket...
			if(data[mid]<v[i])
			{
				if(big==0)
				{
					big=v[i];
				}
				//And the next larger cat is not sit next to the cat we have to change the pocket size until we find the best size of pocket.
				else
				{
					if(v[i]!=big)
					{
						broke=1;
						break;
					}
					else
					{
						big=0;
					}
				}
			}
		}
		if(broke==0)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
		broke=0;
		mid=(l+r)/2;
		big=0;
	}
	//Print the smallest size of pocket that can rearrange the cats.
	printf("%d",data[l]);
	return 0;
}
