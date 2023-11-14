//
// Created by Hanh Hoang on 14.11.2023.
//
//POINTER TO A READER FUNCTION
//Write a function called filter_alpha. The function takes three parameters:
//
//Character pointer (=string)
//String maximum size including terminating nul character
//        Pointer to a function that takes no parameters and returns a character
//        Filter_alpha calls the function given as a parameter to read input one character at a time until a newline is read,  the maximum size is reached, or the read character is a zero. Function must ensure that the string is always properly terminated. Function saves the received character in the string only if the character is a letter. Filter alpha returns the total number of characters it has read. The count must include letters and other characters except zero.
//
//My_getchar reads a character and returns it. When end of input occurs my_getchar returns zero.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MY_STR_SIZE 20

char my_getchar(void);
int filter_alpha(char *str, int max_size, char (*readCharacter)(void)){
    int count =0;
    int read_nr = 0;
    char character;
    do{
        character = readCharacter();
        if(character != 0){
            ++read_nr;
        }
        if(isalpha(character)){
            str[count] = character;
            count++;
        }
    }while((character)!='\n' && count<(max_size-1) && character!=0);
    //while((character)!='\n' && count<(max_size-1) && character!=0){
    //    if(isalpha(character)){
    //        str[count] = character;
    //        count++;
    //    }
    //    character = readCharacter();
    //    ++read_nr;

    //}

    str[count]='\0';
    return read_nr;
}
int main(int arcg, char **argv)
{
    char str[MY_STR_SIZE] = { 0 };
    int count = 0;

    do {
        count = filter_alpha(str, MY_STR_SIZE, my_getchar);
        printf("%d:%d:%s\n", count, strlen(str), str);
    } while (count > 0);

    return 0;

}