#include <stdio.h>
void main()
{
    int t,f=0;
    while(f==0)
    {
        f=1;
    scanf("%d",&t);
    if(t>4000||t<0)
    f=0;
    }
    for(int i=0;i<t;i++)
    {
        int n;
        int max=0,pos=0,c,c1=0;
        scanf("%d",&n);
        if(n>1000||n<0)
        {
            i-=1;
            continue;
            
        }
         int h[n];
         for (int j=0;j<n;j++)
         {
           scanf("%d ",&h[j]);
           if(h[j]>150||h[j]<0)
           {
              j-=1; 
           }
         }
         max=0;pos=0;
         for(int j=0;j<n-1;j++)
         {
            c=0;
            c1=0;
            for(int k=j+1;k<n;k++)
            
            {
             if(h[j]<=h[k] && c1==0)
                {
                    c++;
                    c1=1;
                }
            else if(h[j]>h[k]&&c1==0)
                {
                    c++;
                }
              
                
            }
            
            
            if(c>=max)
            {
                max=c;
                pos=j;
            }
        }
        
        printf("%d\n",pos+1);
    }
    
}