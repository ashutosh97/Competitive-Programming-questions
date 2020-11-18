 vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
      int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int target=-nums[i];
            int f=i+1,b=n-1;
            while(f<b)
            {
               int sum=nums[f]+nums[b];
                if(target<sum)
                    b--;
                else if(target>sum)
                    f++;
                else
                {
                    vector<int> arr(3,0);
                 arr[0]=nums[f],arr[1]=nums[b],arr[2]=nums[i];
                    res.push_back({nums[f],nums[i],nums[b]});
                 while(f<b&&nums[f]==arr[0])
                     f++;
                 while(f<b&&nums[b]==arr[1])
                     b--;
                }
            }
            while(i+1<n&&nums[i+1]==nums[i])
                i++;
        }
        return res;
    }
