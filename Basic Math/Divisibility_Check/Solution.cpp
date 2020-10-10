#include<bits/stdc++.h>
using namespace std;
int main()
{
	char amp[100];
	cin.getline(amp,99,'\n');
	int len=strlen(amp);


	int arr[10]={0};

	int count=0,i=0;
	int start=0;
	for(int l=start;l<=len;l++)
	{

		if(amp[l]==' ' || amp[l]=='\0')
		{
			//cout<<"hi "<<l<<" "<<start<<" ";
			count++;
			for(int m=l-1,n=0;m>=start;m--,n++)
			{
				arr[i]+= (amp[m]-'0')*pow(10,n);

			}

			if(l==len)
				break;
		i++;	
		start=l+1;
		}

	}
	
	sort(arr,arr+count);
	int ans=1;
	for(int a=count-2;a>=0;a--)
	{
		if(arr[count-1]%arr[a]!=0)
		{
			ans=0;
			break;
		}
	}

	cout<<ans;
	return 0;
}