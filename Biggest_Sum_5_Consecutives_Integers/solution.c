#include <stdlib.h>
#include <stdio.h>

int main(){
    int i;
    int size = 81; //SIZE OF THE ARRAY
    int sum;
    int biggestSum;
    int array[]  =  {1, 3, -5, 8, -9, 13, -2, -3, 8, 4, 3, 6, 1, 2, -2, -4, 8, -4, 1, 8, 2, 1, 3, 1, 2, 3, 7, 8, -9, 5, 4, 3, 2, 4, 1, 2, 6, 6, 7, -15, 9, 7, 8, 16, -10, 1, 2, 6, 6, 4, -5, 2, 2, 3, 6, 7, 8, 1, 2, 3, 3, 4, 5, 6, 1, -5, 7, -9, 10, 1, 3, 4, 8, 7, 6, 4, 1, 1, 2, 3, 1};
    
    //FIRST SUM
    sum = array[0] + array[1] + array[2] + array[3] + array[4];
    biggestSum = sum;

    //OTHER SUMS
    for(i = 1; i < (size - 4); i++){ //THERE ARE (size - 4) POSSIBLE SUMS, BUT WE ALREADY MADE 1, SO i STARTS AT 1
        sum = sum - array[i - 1] + array[i + 4]; //REMOVE THE FIRST OF THE OLD SUM, AND ADD THE NEW INTEGER
        if(sum > biggestSum){
            biggestSum = sum;
        }
    }
    printf("biggestSum = %d\n", biggestSum); //PRINT THE RESULT
}