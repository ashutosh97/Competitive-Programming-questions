// Traverse from top left to bottom right of 2d array m X n
// from each cell u can go to the cell on right or down
// return the maximum sum possible
import java.util.*;
public class problem
{
public static void main(String[] args)
{
    Scanner sc = new Scanner(System.in);
    int X,Y; //X:number of rows, Y: number of columns(X=Y) because square
    System.out.println("Enter size");
    X=sc.nextInt();
    Y=X;
    int[][] Cost= new int[X][Y];
    for(int i=0;i<X;i++)
    {
        for(int j=0;j<Y;j++)
        {
            //Take input the cost of visiting cell (i,j)
            Cost[i][j]=sc.nextInt();
        }
    }

    int[][] MaxCost= new int[X][Y];

    MaxCost[0][0] = Cost[0][0];

   
   for(int j=1;j<Y;j++)
        MaxCost[0][j] = MaxCost[0][j-1] + Cost[0][j];

    
   for(int i=1;i<X;i++)
        MaxCost[i][0] = MaxCost[i-1][0] + Cost[i][0];

   for(int i=1;i<X;i++)
    {
        for(int j=1;j<Y;j++)
        {
            
            MaxCost[i][j] = Math.max(MaxCost[i-1][j],MaxCost[i][j-1]) + Cost[i][j];
        }
    }

    System.out.println(MaxCost[X-1][Y-1]);
    
}
}