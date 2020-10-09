#include <bits/stdc++.h>
using namespace std;

int main()
{
// ios_base::sync_with_stdio(0);
// cin.tie(0);
while(1)
{
	int n;
	cin >> n;
	if(n == 0)
	break;
	stack<int> st;
	int k = 0, i = 0;
	int temp;
	while(i < n) 
	{
		cin >> temp;
		while(st.size() && st.top() == k+1)
		k++, st.pop();
		if(temp != k+1)
		st.push(temp);
		else
		k++;
		i++;
	}
	while(st.size() && st.top() == k+1)
		k++, st.pop();
	cout << ((k==n) ? "yes" : "no") << endl;
}

return 0;
}
