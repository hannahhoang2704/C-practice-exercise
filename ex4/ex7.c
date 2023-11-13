//
// Created by Hanh Hoang on 4.9.2023.
//
#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value);

int main(){
    int guess_nr;
    int fail_read=0;
    while(fail_read<3){
        printf("Guess how much money I have\n");
        if (read_positive(&guess_nr)){
            printf("You didn't get it right. I have %d euros.\n", guess_nr*2+20);
        }else{
            fail_read++;
        }
    }
    printf("I give up! See you later!\n");
    return 0;
}

bool read_positive(int *value){
    bool successful_read = false;
    int input_nr=0;
    printf("Enter a positive number: ");
    if(scanf("%d", &input_nr)!=1){
        while (getchar() != '\n');
        printf("Incorrect input\n");
    }else{
        if(input_nr >= 0){
            *value = input_nr;
            successful_read = true;
        }else{
            printf("Negative input\n");
        }
    }
    return successful_read;
}
