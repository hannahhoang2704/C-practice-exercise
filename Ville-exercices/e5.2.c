//
// Created by Hanh Hoang on 14.11.2023.
//
//POINTER TO A CHARACTER OUTPUT FUNCTION
//Write a function named print_string. Print_string returns number of characters it prints.
// Print_string takes two parameters: a character pointer (the string to print) and a pointer to a function that takes a char as parameter and returns no value.
// Print_string must use the function pointer to print the string character by character and it may not modify the string it prints.

#include <stdio.h>

typedef void (*charPrint)(char);

int print_string(char *str, charPrint printChar){
    int count = 0;
    while(str[count]!='\0'){
        printChar(str[count]);
        count++;
    }
    return count;
}

void printChar(char character){
    putchar(character);
}