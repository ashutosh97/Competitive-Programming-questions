int Solution::maxSubArray(const vector<int> &A) {
    int s=INT_MIN,n = A.size(),i,j,m=0,mi=INT_MAX,ma = INT_MIN;
    int arr[n];
    memset(arr,0,sizeof(arr));
    
    for(i=0;i<n;i++)
    {
        m+=A[i];
       arr[i] = m; 
    }
    if(n==1)
    return A[0];
    s=arr[0];
    for(i=0;i<n-1;i++)
    {
        mi = min(mi,arr[i]);
        s = max(s,arr[i+1]-mi);
    }
    return s;
}
