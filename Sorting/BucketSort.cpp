#include<bits/stdc++.h>
using namespace std;
void BucketSort(vector<float>& arr){
    //creating buckets
    vector<float> b[arr.size()];
    //filling buckets
    for(int i=0;i<arr.size();i++){
        int bucket_index=arr.size()*arr[i];
        b[bucket_index].push_back(arr[i]);
    }
    //sorting individual buckets
    for(int i=0;i<arr.size();i++){
        sort(b[i].begin(),b[i].end());
    }
    //concatinating individual buckets
    int index=0;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<b[i].size();j++){
            arr[index++]=b[i][j];
        }
    }

}
int main(){
    vector<float> arr= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    BucketSort(arr);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
