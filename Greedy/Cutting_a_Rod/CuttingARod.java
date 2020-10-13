/**
 * Time Complexity : O(n^2) 
 * which is much better than the 
 * worst case time complexity of Naive Recursive implementation.
 */

import java.util.*;
import java.io.*;

class CuttingARod {

    public static int cutCutCut(int price[], int size) {

        int memory[] = new int[size+1];
        memory[0] = 0;
        
        for(int i=1; i<=size; i++){
            int maximum = Integer.MIN_VALUE;
            for(int j=0; j<i; j++) {
                maximum = Math.max(maximum, price[j]+memory[i-j-1]);
            }
            memory[i] = maximum;
        }
        return memory[size];
    }

    public static void main(String[] args) {
        int price[] = new int[] {1, 5, 8, 9, 10, 17, 17, 20};
        int size = price.length;
        System.out.println("Maximum Profit: " +
                            cutCutCut(price, size));
    }
}