#include<bits/stdc++.h>
using namespace std;

void swapVectors(vector<int> &A, vector<int> &B){
    int temp = A[0];
    A[0] = B[0];
    B[0] = temp;
    
    temp = A[1];
    A[1] = B[1];
    B[1] = temp;
    
}

bool myComp(vector<int> A, vector<int> B){
    return A[0]<B[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), myComp);
        for(int i=0; i<intervals.size();){
            int small = intervals[i][0];
            int big = intervals[i][1];
            int j = i+1;
            // if(intervals[j][0]<small && intervals[j][1]<small){
            //     swapVectors(intervals[i], intervals[j]);
            //     continue;
            // }
            while(j<intervals.size() && intervals[j][0] <= big ){
                small = min(small, intervals[j][0]);
                big = max(big, intervals[j][1]);
                j++;
            }
            vector<int> temp;
            temp.push_back(small);
            temp.push_back(big);
            res.push_back(temp);
            i = j;
        }
        return res;
    }
};