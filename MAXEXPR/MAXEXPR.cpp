#include<bits/stdc++.h>
using namespace std;
# define ld long double

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){

		int n;
		cin>>n;
		ld k[n],c[n],ck=0,ku=0;
		for(int i=0;i<n;i++){
			cin>>k[i];
			ku+=(1/k[i]);
		}
		for(int i=0;i<n;i++){
			cin>>c[i];
			ck+=k[i]*c[i];
			k[i]=k[i]*k[i];
		}
		if(ck<0)
           cout<<"-1\n";
        else{
            cout<<sqrt(ck*ku)<<" ";
            ld s=ck/ku;
            for(int i=0;i<n;i++)
                cout<<s/k[i] -c[i]<<" ";
            cout<<"\n";
        }
	}
	return 0;
}
