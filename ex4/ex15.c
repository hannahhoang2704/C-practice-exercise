//
// Created by Hanh Hoang on 18.9.2023.
//
#include <stdio.h>
#include <string.h>
#define ARRAYSIZE 40
#define LINE_SIZE 80

void read_string(char *str);

typedef struct menu_item_ {
    char name[50];
    double price;
}menu_item;

int main(void){
    char file_name[LINE_SIZE];
    char line[LINE_SIZE];
    int lc = 0;
    menu_item item_array[ARRAYSIZE];
    FILE *file;
    printf("Enter file's name: ");
    read_string(file_name);
    file = fopen(file_name, "r");
    if(file == NULL){
        fprintf(stderr, "\"%s\" can not be opened\n", file_name);
        return 1;
    }else{
        while(!feof(file) && lc<ARRAYSIZE){
            if(fgets(line, LINE_SIZE, file)!=NULL){
                char *token;
                const char delimeter[2] = ";";
                double price=0;
                token = strtok(line, delimeter);
                if (token!=NULL){
//                    printf("%s\n", token);
                    strcpy(item_array[lc].name, token);
                    token = strtok(NULL, delimeter);
//                    printf("%s\n", token);
                    if(sscanf(token, "%lf", &price)==1){
                        item_array[lc].price = price;
//                        printf("%.2lf\n", item_array[lc].price);
                    }
                }
                lc++;
            }
        }
        fclose(file);
    }
    //Print array in formatted column
    for (int i = 0; i<lc; i++){
        printf("Price:%8.2lf\tName: %s\n", item_array[i].price, item_array[i].name);
    }
    return 0;
}

void read_string(char *str) {
    fgets(str, LINE_SIZE, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}
