#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n,k;cin>>n>>k;
    int a[n];long long int mod=1000000007;
    int max=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max)
            max=a[i];
    }
    long int f[max+1];
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++)
        f[a[i]]++;
    vector<long int>v;
    for(int i=0;i<=max;i++)
        if(f[i])
            v.push_back(f[i]);
    long int l=v.size();
    k=k>l?l:k;
    long int dpans[k+1][l],val;
    val=v[0]+1;
    memset(dpans,0,sizeof(dpans));
    dpans[0][0]=1;
    dpans[1][0]=val;
    long int total=0;
    for(int i=2;i<=k;i++)
    	dpans[i][0]=val;
    for(int i=1;i<l;i++)
    	dpans[0][i]=1;
    for(int i=1;i<l;i++)
    	for(int j=1;j<=k;j++){
    		total=((v[i]%mod)*(dpans[j-1][i-1])%mod)%mod;
    		dpans[j][i]=(((dpans[j][i-1])%mod)+(total%mod))%mod;
    	}
    total=(dpans[k][l-1])%mod;
    cout<<total<<endl;
    return 0;
}
