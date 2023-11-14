//
// Created by Hanh Hoang on 14.11.2023.
//
//READ VALUES FROM VARARG LIST
//Write a function called count_args. Function takes an integer pointer and variable number of other arguments as parameters and returns an integer. The variabale arguments are pointers to strings. The end of arguments is indicated by a NULL pointer. The function returns the number of strings.
//Function also counts total number of characters in the strings and stores the total through the first parameter.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
int count_args(int *ptr, ...){
    int nr=0;
    va_list args;
    va_start(args, ptr);
    *ptr = 0;

    char *str = va_arg(args, char*);
    while(str!=NULL){
        while(*str!='\0'){
            *ptr+=1;
            str++;
        }
        nr++;
        str= va_arg(args,char*);
    }
    va_end(args);
    return nr;
}
