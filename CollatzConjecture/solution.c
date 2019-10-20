#include <stdlib.h>
#include <stdio.h>

int main(){
    long int N = 26; //CALCULATING FOR N = 26
    long int biggestValue = 0;
    long int steps = 0;

    while(N != 1){
        if(N%2 == 0){
            N = N/2;
        }else{
            N = N*3 + 1;
        }
        if(N>biggestValue){
            biggestValue = N;
        }
        steps++;
    }

    printf("Number of Steps: %ld BiggestValue: %ld", steps, biggestValue);

}