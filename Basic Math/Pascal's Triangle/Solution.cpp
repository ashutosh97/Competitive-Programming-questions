#include <bits/stdc++.h> 
  
using namespace std; 
void printPascal(int n) 
{ 
      
for (int line = 1; line <= n; line++) 
{ 
    int Col = 1;  
    for (int i = 1; i <= line; i++)  
    { 
          
        
        cout<< Col<<" ";  
        Col = Col * (line - i) / i;  
    } 
    cout<<"\n"; 
} 
} 
  
 
int main() 
{ 
    int t;
    cin>>t;

    while(t--){
     int n;
    cin>>n;
    printPascal(n);
    }
    
    return 0; 
} 