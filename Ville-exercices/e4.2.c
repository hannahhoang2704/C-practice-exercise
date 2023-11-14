//
// Created by Hanh Hoang on 14.11.2023.
//
//COUNT SPECIFIED CHARACTERS IN A FILE
//Write a function called count_chars that takes a string and a file pointer as parameters. The string contains characters to count from the file. Function returns the total count of occurrence of any characters in the string. For example if the string is "R" function counts number of capital Rs in the file. String "abc" counts the total number of letters a, b, and c in the file. The function must call my_gets to read the file. my_gets works the same way as fgets.
//
//Please note that file pointer that is passed to count_characters is a test bench file pointer. Real file access is disabled in ViLLE for security reasons. So you can't use normal file functions (feof, fseek, fread, etc.) with the file. You can only call my_gets to read data from the test bench file.
//
//char *my_gets(char *line, int size, FILE *stream);
//int count_chars(const char *characters, FILE *stream);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


char *my_gets(char *line, int size, FILE *stream);
int count_chars(const char *characters, FILE *stream);
int count_chars(const char *characters, FILE *stream){
    char line[256];
    int count=0;
    while(my_gets(line,256, stream) != NULL){
        for(int i =0; line[i]!= '\0'; i++){
            if (strchr(characters, line[i])!=NULL){
                count++;
            }
        }
    }

    return count;
}