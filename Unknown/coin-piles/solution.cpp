#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,k,a[100],d[100],rem[100],low,hi,removals,d_idx,min_removals;
	unordered_map<int,int>freq;

	scanf("%d\n", &t);
	while(t--) {
	    scanf("%d %d\n", &n, &k);
	    for(int lc = 0; lc < n; lc++) {
	        scanf("%d" , &a[lc]);
	    }

	    sort(a,a + n);
	    d_idx=0;
        freq.clear();
	    for(int lc = 0; lc < n; lc++) {
	        int key = a[lc], cnt = 0;
	        while(lc < n && a[lc] == key)
	            lc++;
	        lc--;
	        d[d_idx] = key;
            d_idx++;
	    }

	    low = 0;
        min_removals = INT_MAX;
	    while(low < d_idx) {
	        int cur = d[low];
            removals = 0;
	        for(int lc = 0; lc < n; lc++) {
	            if(a[lc] < cur)
	                rem[lc] = a[lc];
	            else if(a[lc] >= cur && a[lc] <= (cur + k))
	                rem[lc] = 0;
	            else if(a[lc] > (cur + k))
	                rem[lc] = (a[lc] - (cur + k));

	            removals += rem[lc];
	        }
	        min_removals = min(min_removals, removals);
	        low++;
	    }
	    printf("%d\n",min_removals);
	}
	return 0;
}