//
// Created by Hanh Hoang on 14.11.2023.
//
//Write a function that receives string as a parameter.
//Function finds all occurrences of letter 't' and replaces them with '*'. Function returns no value.
#include <stdio.h>
#include <string.h>


void replace(char *str)
{char t[] = "t";
    int output;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i]=='t'){
            str[i] = '*';
        }
    }
}
int main(void)
{
    char test1[] = "Two teas to thirtytwo";
    char test2[] = "this is a t-test";
    char test3[] = "where have all the flowers gone there's not a single one left here";

    replace(test1);
    replace(test2);
    replace(test3);

    printf("%s\n", test1);
    printf("%s\n", test2);
    printf("%s\n", test3);


    return 0;
}