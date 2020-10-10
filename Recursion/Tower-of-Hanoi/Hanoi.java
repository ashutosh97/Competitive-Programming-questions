import java.util.Scanner;

class Hanoi{
    public static void main(String[] args){
        Scanner newInput = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n = newInput.nextInt();
        char[] rod = new char[]{'A','B','C'};
        move(n,rod[0],rod[2],rod[1]);
    }


    public static void move(int n, char from, char to, char aux){
        if (n == 1) {
            System.out.println("Move " + n + " From " + from + " to " + to);
            return;
        }
        move(n-1,from,aux,to);
        System.out.println("Move " + n + " From " + from + " to " + to);
        move(n-1,aux,to,from);
    }
}