#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef vector < int > vi; 
typedef pair < long long int, long long int > pii;
typedef vector < pii > vii;
typedef long long int i64;
int d;
i64 k;
bool byPairs(pii left, pii right)
{
    if(left.first != right.first)
        return left.first < right.first;
    return left.second < right.second;
}
i64 sol(vii &nums)
{
    sort(nums.begin(), nums.end(), byPairs);
    
    i64 ans = -1ll;
    i64 last = -1ll;
    int i = 0;
    while(k>0ll && i < (int)nums.size())
    {
        if(last < nums[i].first) // no overlap
        {
            i64 len = nums[i].second - nums[i].first + 1ll;
#ifdef DEBUG

            cout<<nums[i].first<<" --- "<<nums[i].second<<" : "<<len<< "  > " <<k<<endl;
#endif                  

            if(len < k)
                k-=len, last = nums[i].second, i++;
            else
            {
                ans = nums[i].first + k - 1ll, k = 0ll; 

            }
        }
        else // overlap
        {
            if(nums[i].second <=  last) i++;
            else nums[i].first = last + 1;
        }
    }
    return ans;
}
int main()
{
#ifdef DEBUG
  clock_t begin = clock();
#endif   
  int test_cases;
  scanf("%d", &test_cases);
  while(test_cases--)
  {
    cin>>d>>k;
    vii nums = vii();
    for(int i = 0; i < d; i++)
    {
      pii x;
      cin>>x.first>>x.second;
      nums.push_back(x);
    }
    cout<< sol(nums) <<endl;
  }
#ifdef DEBUG
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  printf("%.10f\n", elapsed_secs);
#endif   
}


