import java.util.Scanner;
import java.lang.Math;

public class minsteps
{
    public static Scanner s=new Scanner(System.in);

    public static void main(String[] args)
    {
        int n = s.nextInt();
        System.out.println(countStepsTo1(n));
    }

    public static int countStepsTo1(int n)
    {
        if(n<=1)
            return 0;
        if(n==2 || n==3)
            return 1;
        int ans[]=new int[n+1];

        ans[0]=0;
        ans[1]=0;
        ans[2]=1;
        ans[3]=1;



        for(int i=4;i<n+1;i++)
        {
            int x=Integer.MAX_VALUE;
            int y=Integer.MAX_VALUE;
            int z=ans[i-1]+1;

            if(i%3==0)
                x=ans[i/3]+1;
            if(i%2==0)
                y=ans[i/2]+1;

            ans[i]=Math.min(x,Math.min(y,z));
        }

        return ans[n];
    }


}
