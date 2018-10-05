#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int n,i,j,k;
	cout<<"Enter Value Of n: ";
	cin>>n;
	int space=n-1;
	for(i=1; i<=n;i++)
	{
		cout<<endl;
		for(k=space; k>=1;k--)
		{
			cout<<" ";
		}
		space--;
		for(j=1; j<=i; j++)
			cout<<j;
		for(j=i-1; j>=1; j--)
		cout<<j;
	}
	cout<<endl;
//-------------------------------------------------------------------
	cout<<endl;
	cout<<"Enter Value Of n: ";
	cin>>n;
	space=n-1;
	for(i=1; i<=n;i++)
	{
			cout<<endl;
	for(k=space;k>=1;k--)
		cout<<" ";
	for (j=1; j<=(2*i)-1; j++)
		cout<<'*';
	space--;
	}
	space=1;
	for (i=1; i<=n-1; i++)
	{
		cout<<endl;
		for(k=space;k>=1; k--)
			cout<<" ";
		for(j=1;j<=2*(n-i)-1;j++)
			cout<<'*';
		space++;
	}
	getch();
}

/*
Enter Value Of n: 5


    1
   121
  12321
 1234321
123454321

Enter Value Of n: 6

     *
    ***
   *****
  *******
 *********
***********
 *********
  *******
   *****
    ***
     *

*/
                                                                                
                                                                                
                                                                                
                                                                                

                                                                                
