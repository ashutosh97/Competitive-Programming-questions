#include <stdio.h>

int data[100];

int fibonacci(int x){
    if(x <= 2)
        return 1;
    if(data[x] != 0){
        return data[x];
    }
    else{
        data[x] = fibonacci(x-1) + fibonacci(x-2);
        return data[x];
    }
}
int main(void){
    printf("%d ", fibonacci(40)); return 0;
}
