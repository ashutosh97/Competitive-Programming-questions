import java.io.*;
import java.util.*;

class Codechef
{
    public static void main(String args[]) throws IOException
        {  
           
           BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
           int t=Integer.parseInt(br.readLine());
           Codechef obj = new Codechef();
           for(int i=0;i<t;i++)
           {
               int n= Integer.parseInt(br.readLine());
               String s1= br.readLine();
               String s2= br.readLine();
               int counter1=0;
               int counter2=0;
               for(int j=0; j<n ; j++)
               {
                   if(s1.charAt(j)=='1')
                   counter1++;
                }
                 for(int j=0; j<n ; j++)
               {
                   if(s2.charAt(j)=='1')
                   counter2++;
                }
                
                if(counter1==counter2)
                System.out.println("YES");
                else
                System.out.println("NO");
            }
        }
    }
