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
            int max=0;
            int counter=0;
            int n= Integer.parseInt(br.readLine());
            String g= br.readLine();
            String f= br.readLine();
            StringTokenizer st= new StringTokenizer(g);
            StringTokenizer ss= new StringTokenizer(f);
     
            while(st.hasMoreTokens())
            {
                int goals= Integer.parseInt(st.nextToken());
                int fouls= Integer.parseInt(ss.nextToken());
                
                counter= (goals*20)-(fouls*10);
                if(counter<0)
                counter=0;
                if(counter>max)
                max= counter;
                
              
                
                counter=0;
            }
            System.out.println(max);
        }
    }
}
            