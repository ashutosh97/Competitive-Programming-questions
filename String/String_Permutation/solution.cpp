#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int main()
{
    string a,b;
    cout<<"Enter two strings \n";
    cin>>a>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    if(a==b)
        cout<<"These strings are permutations of each other\n";
    else
        cout<<"These strings are NOT permutations of each other\n";
    

    return 0;   
}



