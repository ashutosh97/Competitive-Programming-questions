class rod_cutting
{
  static int cut_rod(int price[], int n)
  {
    // Declaring a 2D array, T
    int T[][] = new int[n-1][n+1];

    // Initializing the array to all zeros
    for(int i=0; i < n-1; i++)
    {
      for(int j=0; j < n+1; j++ )
      {
        T[i][j] = 0;
      }
    }

    for(int i=0; i < n-1; i++)
    {
      for(int j=0; j < n+1; j++ )
      {
        // First column => 0 length of rod => 0 profit
        if(j == 0) {
          continue;
        }

        // First row => T[i-1][j] doesn't exist so just pick the second value
        else if(i == 0) {
          T[i][j] = price[i] + T[i][j-i-1];
        }

        // where j <= i => T[i][j-i-1] doesn't exist so just pick the first value
        else if(j-i-1 < 0) {
          T[i][j] = T[i-1][j];
        }

        // using the whole expression
        else {
          T[i][j] = Math.max(T[i-1][j], (price[i] + T[i][j-i-1]));
        }
      }
    }
    return T[n-2][n];
  }

  public static void main(String args[]) 
  { 
     int price[] = new int[] {2,5,7,8}; 
     int n = 5;
     System.out.println("Maximum profit is " + cut_rod(price, n)); 
    } 
}
