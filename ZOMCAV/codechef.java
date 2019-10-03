import java.util.*;
import java.io.*;
class codechef
{
    public static void main(String args[])throws IOException
    {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int t= Integer.parseInt(br.readLine());
        for(int phi=0; phi<t;phi++)
        {
            int n= Integer.parseInt(br.readLine());
            String ra= br.readLine();
            String zo= br.readLine();
            
            int radpow[]= new int[n];
            
            int starting[]= new int[n];
            
            for(int i=0;i<n;i++)
            {
                starting[i]=0;
            }
            
                
            
            StringTokenizer st = new StringTokenizer(ra);
            
            int cou=0;
            
            while(st.hasMoreTokens())
            {
                long val = Long.parseLong(st.nextToken());
                
                int start= (int)Math.max(0, cou-val);
                int stop=  (int)(cou+val+1);
                
                
                cou++;
                
                
                starting[start]+=1;
                if(stop<=n-1)
                starting[stop]-=1;
               
                
            }
            
            
            
            
            cou=0;
            for(int i=0;i<n;i++)
            {
                cou+=starting[i];
                if(cou<0)
                cou=0;
                radpow[i]+=cou;
            }
            
            
            
            
            StringTokenizer newst= new StringTokenizer(zo);

            long xor=0;
            for(int i=0;i<n;i++)
            {
                xor= (xor^radpow[i])^Long.parseLong(newst.nextToken());
            }
      
            if(xor==0)
           System.out.println("YES");
           else
           System.out.println("NO");
        }
    }
}
           