#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;int a[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int j=1;int good =1;int cnt=0;int t=0;

        for(int i=1;i<n;i++){
                if(i>=6)t++;
            for(j=i-1;j>=t;j--){

                if(a[j]>a[i]){
                cnt=1;}

                else {
                cnt=0;
                break;}

            }

            if(cnt==1)
            good++;

        }

        cout<<good<<endl;
    }


}
