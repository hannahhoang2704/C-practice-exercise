//
// Created by Hanh Hoang on 18.9.2023.
//
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define STR_LENGTH 50

void read_string(char *str);

int main(void){
    FILE *my_file;
    char file_name[STR_LENGTH];
    int count_nr =0;
    int value;
    int min = INT_MAX;
    int max = INT_MIN;

    printf("Enter file name: ");
    read_string(file_name);

    my_file = fopen(file_name, "r");
    if (my_file==NULL){
        fprintf(stderr, "\"%s\" not found.\n", file_name);
        return 1;
    }else{
       while(fscanf(my_file, "%d", &value)==1 && !feof(my_file)){
               printf("%d\n", value);
               ++count_nr;
               if(value<min){
                   min=value;
               }
               if(value>max){
                   max = value;
               }
           }
       }
        printf("File %s includes %d numbers, max= %d, min = %d", file_name, count_nr, max, min);
        fclose(my_file);
    return 0;
}
void read_string(char *str) {
    fgets(str, STR_LENGTH, stdin);
//    printf("%s\n", str);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}