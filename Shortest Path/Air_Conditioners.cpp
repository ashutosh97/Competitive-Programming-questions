/*
https://codeforces.com/contest/1547/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t,n,a,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ll arr[m];
        ll res[n];
        ll k=1;
        unordered_map <ll,ll> mp;
        for(ll i=0;i<n;i++){
            res[i]=LLONG_MAX;
        }
        for(ll i=0;i<m;i++){
            cin>>arr[i];
            k=max(k,arr[i]);
        }
        for(ll i=0;i<m;i++){
            cin>>a;
            if(mp[arr[i]]) mp[arr[i]]=min(mp[arr[i]],a);
            else mp[arr[i]]=a;
        }
        ll j=1;
        while(mp[j]==0) j++;
        for(ll i=0;i<n;i++){
            if(mp[i+1]){
                if(mp[j]+abs(j-1-i)<mp[i+1]){
                    res[i]=mp[j]+abs(j-1-i);
                }
                else{
                    res[i]=mp[i+1];
                    j=i+1;
                }
            }
            else{
                res[i]=mp[j]+abs(j-1-i);
            }
        }
        j=k;
        for(ll i=n-1;i>-1;i--){
            if(mp[i+1]){
                if(mp[j]+abs(j-1-i)<mp[i+1]){
                    res[i]=min(mp[j]+abs(j-1-i),res[i]);
                }
                else{
                    res[i]=min(mp[i+1],res[i]);
                    j=i+1;
                }
            }
            else{
                res[i]=min(mp[j]+abs(j-1-i),res[i]);
            }
        }
        for(ll i=0;i<n;i++){
            cout<<res[i]<<' ';
        }
        cout<<'\n';
    }
}