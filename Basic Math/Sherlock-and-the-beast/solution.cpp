#include <bits/stdc++.h>

using namespace std;


// Complete the decentNumber function below.

void decent(int digits)
{
    int flag=0;

    if(digits==4 || digits==7 || digits<3)
        flag=0;
    else if(digits==5)
    {
        flag=1;
        cout<<"33333\n";
        
    } 
    else if(digits%3 ==0)
    {
        flag=1;
        //(no. of times, what needs to be printed)
        cout<<string(digits,'5')<<"\n";
        
    }

    else if(digits>=8)
    {
        
        int remain3,remain5,temp;
  
            temp=digits%3;
            flag=1;
        if(temp==1)
        {
            remain5=digits-10;
            remain3=10;
        }
        else if(temp==2)
        {
            remain5=digits-5;
            remain3=5;
        }
        
        cout<<string(remain5,'5')<<string(remain3,'3')<<"\n";
    }
        

    if(flag==0)
        cout<<"-1\n";

        
}

int main()
{
    int cases,input;
    cin>>cases;
    while(cases-->0)
    {
        cin>>input;
        decent(input);
    }
    return 0;
}