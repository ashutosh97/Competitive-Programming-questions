#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t,n,c;
  cin>>t;
  vector<long long> ans;
  
  while(t--){
    cin>>n>>c;
    long long x[n];
    long long mind=LLONG_MAX;
    for(long long i=0;i<n;i++){
      cin>>x[i];
      mind=min(x[i],mind);
    }
    sort(x,x+n);

    long long low=mind;
    long long high=x[n-1]-x[0];
    long long mid;

    while(low < high){
      mid = low+(high-low+1)/2;
      long long cows=1;
      long long idx=0;
      for(long long i=1;i<n;i++){
        if(x[i]-x[idx] >= mid) {cows++; idx=i;}
      }
      if(cows >= c) low=mid;
      else high=mid-1;
    }
    ans.push_back(low);
  }

  for(vector<long long>::iterator it=ans.begin();it!=ans.end();it++){
    cout<<*it<<endl;
  }
  return 0;
}
