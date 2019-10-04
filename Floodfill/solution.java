import java.util.Arrays;
import java.util.Scanner;

public class water {
public static void main(String[] args){
Scanner kb=new Scanner(System.in);
System.out.println("Enter the dimensions of the map:");
int n=kb.nextInt();
int m=kb.nextInt();
System.out.println("Enter the map:");
char[][] x=new char[n][m];
for(int i=0;i<n;i++)
x[i]=kb.next().toCharArray();
String str="";
int count=0;
for(int i=0;i<n;i++){
for(int k=0;k<m;k++){
if(x[i][k]!='#'&&x[i][k]=='w'){
fillGrid(x, i, k);
display(x);
count++;
System.out.println(count);
}
}
}
if(count==1)
System.out.println("\nThere is "+count+" body of water.");
else
System.out.println("\nThere are "+count+" bodies of water.");
}
public static void fillGrid(char[][] arr, int r, int c) {
if (inBounds(arr,r,c)&&arr[r][c] == 'w'){
arr[r][c] = '#';
fillGrid(arr,r + 1, c);
fillGrid(arr,r - 1, c);
fillGrid(arr,r, c + 1);
fillGrid(arr,r, c - 1);
}
}

public static boolean inBounds(char[][] arr, int r, int c) {
return r>=0&&r<arr.length&&c>=0&&c<arr[0].length;
}

public static void display(char[][] arr){
System.out.println("\nGrid: ");
for (int i = 0; i < arr.length; i++){
for (int j = 0; j < arr[i].length; j++)
System.out.print(arr[i][j]);
System.out.println();
}
}
}
