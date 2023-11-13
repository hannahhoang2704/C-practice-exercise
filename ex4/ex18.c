//
// Created by Hanh Hoang on 26.9.2023.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int read_nr();
int main(void){
    srand(time(NULL));
    int nr;
    nr =read_nr();
    while(nr>=0){
        int random_nr=rand();
        int res;
        printf("Random number %d in hexadecimal 0x%02X\n", random_nr, random_nr);
        printf("Shifting number to the right %d bits\n", nr);
        res = (random_nr>>nr) & 0x3F;
        printf("After shifting 0x%02X\n", res);
        nr = read_nr();
    }
    return 0;
}
int read_nr(){
    int nr;
    do{
        printf("Enter number to from 0-15 or negative number to stop: ");
        if (scanf("%d", &nr)!=1){
            while (getchar() != '\n');
            printf("Invalid input.\n");
        }else if(nr<=15){
            return nr;
        }
    }while(nr>15);
    return nr;
}