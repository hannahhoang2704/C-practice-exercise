//
// Created by Hanh Hoang on 14.11.2023.
//
//READS AND PARSE INPUT
//Write a program that reads input lines using read_line-function. read_line returns true if input was read and false when input ends. Each line contains two numbers and a command "add", "sub", "mul", or "div". Program reads lines one by one and checks that input is valid (first 2 integers then a string that is a valid command). If line is not properly formatted the program prints the line and displays an error message. For each properly formatted line the program prints out a calculation which is determined by the command.
//
//For example input that contains:
//7 2 sub
//43 -3 add
//
//Will make the program print:
//7 - 2 = 5
//43 + -3 = 40
//
//If the input can't be parsed then program must print the invalid line and an error message that describes the location of the error. See the example solution output for details.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


/* call this function to read input */
bool read_line(char *line, size_t size);

int main(void){
    char line[256];
    int nr1;
    int nr2;
    char command[10];
    char sign;
    int result=0;
    while(read_line(line, sizeof(line))){
        int input = sscanf(line, "%d %d %s", &nr1, &nr2, command);
        if(sscanf(line, "%d %d %s", &nr1, &nr2, command)!=3){
            printf("Input: \"%s\" ", line);
            if(input == 2){
                if (!isdigit(command[0])) {
                    printf("Unknown command: %s\n", command);
                } else {
                    printf("Invalid argument in position: 2\n");
                }
            }else{
                printf("Invalid argument in position: %d\n", input + 1);
            }

        }else{
            if(strcmp(command, "add")==0){
                result = nr1 + nr2;
                sign = '+';
            }else if(strcmp(command, "sub")==0){
                result = nr1 - nr2;
                sign = '-';
            }else if(strcmp(command, "mul")==0){
                result = nr1*nr2;
                sign = '*';
            }else if(strcmp(command, "div")==0){
                if(nr2!=0){
                    result = nr1/nr2;
                    sign = '/';
                }
            }else{
                printf("Input: \"%s\" ", line);
                printf("Unknown command: %s\n", command);
                continue;
            }
            printf("%d %c %d = %d\n", nr1, sign, nr2, result);
        }
    }
    return 0;
}