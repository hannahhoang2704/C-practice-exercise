//
// Created by Hanh Hoang on 18.9.2023.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LINE_SIZE 80
#define LINE_NR 100
#define STR_LENGTH 80

void read_string(char *str);

int main(void){
    char array[LINE_NR][LINE_SIZE];
    FILE *my_file;
    int line_count=0;
    char file_name[50];

    printf("Enter file's name: ");
    read_string(file_name);

    //Read the file
    my_file = fopen(file_name, "r");
    if(my_file==NULL){
        fprintf(stderr, "\"%s\" can not be opened.\n", file_name);
        return 1;
    }else{
        printf("Reading the file %s\n", file_name);
        while(line_count<LINE_NR && !(feof(my_file))){
            if(fgets(array[line_count], LINE_SIZE, my_file)!=NULL){
                ++line_count;
            }
        }
        printf("Read %d lines from %s\n", line_count, file_name);
        fclose(my_file);
    }

    //Change all letters to uppercase
    for (int row = 0; row<line_count; row++){
//        printf("Line %d: %s\n", row, array[row]);
        for(int i=0; i<strlen(array[row]); i++){
            array[row][i] = toupper(array[row][i]);
        }
//        printf("After convert: Line %d: %s\n", row, array[row]);
    }

    //Write it back to the file
    my_file = fopen(file_name, "w");
    if(my_file==NULL){
        fprintf(stderr, "\"%s\" can not be opened.\n", file_name);
        return 1;
    }else{
        for(int i = 0; i < line_count ; i++){
            fputs(array[i], my_file);
        }
        fclose(my_file);
    }
    return 0;
}


void read_string(char *str) {
    fgets(str, STR_LENGTH, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}
