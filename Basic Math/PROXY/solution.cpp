#include<iostream>
using namespace std;

float att(int act,int cnt,int d){
    float t = (double)cnt/d;
     if(t>=0.75)
       cout<<cnt-act<<endl;
    return t;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int d,cnt=0,i=0,flag=0;
        cin>>d;
              char s[d];
              cin >> s;


        //count of present
        for(i=0;i<d;i++){
            if(s[i]=='P')
            cnt++;
        }

        int act = cnt;

           
                
            if(att(act,cnt,d)<0.75){
            for(i=2;i<d-2;i++){
                if((s[i]=='A') && (s[i-1]=='P' || s[i-2]=='P') && (s[i+1]=='P' || s[i+2]=='P'))
                {
                    cnt++;
                    if(att(act,cnt,d)>=0.75){
                        flag=1;
                        break;
                    }
                  
                }
            }
            if(flag==0)
            cout<<-1<<endl;
            }
            
    }
    return 0;
}
