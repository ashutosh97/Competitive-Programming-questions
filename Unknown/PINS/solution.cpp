#include <iostream>

using namespace std;
int main()
{
    long tcase;
    cin>>tcase;
    while(tcase)
    {
    	//                 <---start form here--->
    	int n;
		cin>>n;
    	cout<<1<<" "<<1;
    	for(int i=0;i<n/2;i++)
    		cout<<0;
    	cout<<endl;
       	tcase--;
	}

	return 0;
}
