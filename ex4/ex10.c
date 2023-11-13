//
// Created by Hanh Hoang on 11.9.2023.
//
#include <stdio.h>
#include <string.h>

int main(void){
    char string[256];
    int stop_called;
    do{
        printf("Enter a string: ");
        fgets(string, 256, stdin);
        printf("%s\n", string);
        if(string[strlen(string)-1] =='\n'){
            string[strlen(string)-1]= '\0';
        }
        printf("Length of string: %lu\n", strlen(string));
        stop_called = strcmp(string, "stop");
//        printf("compare string: %d\n", stop_called);
    }while(stop_called!=0);

}