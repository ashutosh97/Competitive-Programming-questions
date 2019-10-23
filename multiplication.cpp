#include<iostream>
using namespace std;
int main()
{
    int r1,c1,r2,c2,A[10][10],B[10][10],C[10][10],i,j,k;
    cout<<"enter number of rows of first matrix \n";
    cin>>r1;
    cout<<"enter the number of columns of first matrix \n";
    cin>>c1;
    cout<<"enter the number of rows of second matrix \n";
    cin>>r2;
    cout<<"enter the number of columns of second matrix \n";
    cin>>c2;

    if(c1!=r2)
    {
        cout<<"enter the value of column of first matrix = value of row of second matrix \n";
        cout<<"multiplication cannot be done \n";
        return 0;
    }
    
    cout<<"enter elements of matrix A \n";
for(i=0;i<r1;i++)
{
    for(j=0;j<c1;j++)
    {
        cout<<"enter a "<< i+1 << j+1 << ": ";
        cin>>A[i][j];
    }
}
cout<<"enter elements of matrix B ";
for(i=0;i<r2;i++)
{
    for(j=0;j<c2;j++)
    {
        cout<<"enter b "<< i+1 << j+1 << ": ";
        cin>>B[i][j];
    }
}
for(i=0;i<r1;i++)
{
    for(j=0;j<c2;j++)
    {
        C[i][j]=0;

        for(k=0;k<c1;k++)
        { 
            C[i][j]=C[i][j]+A[i][k]*B[k][j];
        }
     }

}
cout<<"output matrix is : \n";
for(i=0;i<r1;i++)
{
    for(j=0;j<c2;j++)
    {
        cout<<" "<<C[i][j];
        if(j == c2-1)
        cout << endl;
    }
    
}
return 0;


}