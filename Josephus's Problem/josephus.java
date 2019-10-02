import java.io.*;
import java.util.Scanner; 
  
class Josephus { 
  
static int josephus(int n, int k) 
{ 
if (n == 1) 
    return 1; 
else
    return (josephus(n - 1, k) + k-1) % n + 1; 
} 
  
  public static void main(String[] args) 
{ 
	Scanner s = new Scnner(System.in);
int n = s.nextInt(); 
int k = s.nextInt(); 
System.out.println("The chosen place is " + josephus(n, k)); 
} 
} 