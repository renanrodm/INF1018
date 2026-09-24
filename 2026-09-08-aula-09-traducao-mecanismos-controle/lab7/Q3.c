#include <stdio.h>


int main(void){

    int square = 0;
    
    for(int i = 1; i <= 10; i++) {
        square = i;
        square = square * square;
        printf("%d\n", square);
    }
    return 0;
}