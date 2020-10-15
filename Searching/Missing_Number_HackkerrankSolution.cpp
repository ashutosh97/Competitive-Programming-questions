#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , m;
    cin >> n;
    vector<int>::iterator it;
    vector<int> first(n);
    for(int i = 0; i < n; i++)
        cin >> first[i];
    cin >> m;
    vector<int> second(m);
    for(int i = 0; i < m; i++)
        cin >> second[i];
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    vector<int> res;
    int i = 0, j = 0;
    while(j < m){
        if(first[i]==second[j]){
            i++; j++;
        }
        else{
            res.push_back(second[j]);
            j++;
        }
    }

    it=unique(res.begin(), res.end());
    res.resize(distance(res.begin(), it));
    for(auto a : res)
        cout << a << " ";
}
