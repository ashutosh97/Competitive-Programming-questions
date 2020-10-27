#include<iostream>
#include<vector>
#include<string>
using namespace std;
string convert(string s, int numRows) {
    vector<string>v(numRows,"");// for storing the new pattern
    int fg=0;//flag for direction
    int n=s.size();
    for(int i=0;i<n;i++){
        if(fg==0){
            int count=0;
            while(i<n&&count<numRows){
                v[count]+=s[i];
                i++;
                count++;
            }
        }
        else{
            int count=numRows-2;
            while(i<n && count>0){
                v[count]+=s[i];
                i++;
                count--;
            }
        }
        fg=1-fg;
        i--;
    }
    //forming the final string
    string ans="";
    for(int i=0;i<numRows;i++){
        ans+=v[i];
    }
    return ans;
}
int main(){
	string inputstr;
	int numRows;
	int testcases;
	cin>>testcases;
	while(testcases--){
		cin>>inputstr;
		cin>>numRows;
		string a=convert(inputstr,numRows);
		cout<<a<<"\n";
	}
	return 0;
}
