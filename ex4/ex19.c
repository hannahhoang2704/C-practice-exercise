//
// Created by Hanh Hoang on 2.10.2023.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAYSIZE 40
#define LINE_SIZE 80

typedef enum {byName, byPrice} sort_order;

typedef struct menu_item_ {
    char name[50];
    double price;
}menu_item;

void read_string(char *str);
sort_order read_choice(void);
int int_comparator(const void *a, const void *b);
int char_comparator(const void *a, const void *b);

int main(void) {
    char file_name[LINE_SIZE];
    int count = 0;
    menu_item menu[ARRAYSIZE];
    char buffer[LINE_SIZE];

    FILE *file;

    printf("Enter file's name: ");
    read_string(file_name);

    file = fopen(file_name, "r");
    if (file == NULL) {
        fprintf(stderr, "\"%s\" can not be opened\n", file_name);
        return 1;
    } else {
        while (!feof(file) && count < ARRAYSIZE) {
            while (fgets(buffer, LINE_SIZE, file) != NULL) {
//                    printf("%s", buffer);
                    if(sscanf(buffer, "%39[^;]", menu[count].name)==1){
                        if(sscanf(buffer, "%*[^;];%lf", &menu[count].price)==1){
                            ++count;
                        }
                    }
                else{
                    while(fgetc(file)!='\n');
                }
            }
        }
        fclose(file);
    }
    //read the file;
    printf("The unsorted array is: \n");
    for (int i = 0; i<count; i++){
        printf("Price:%8.2lf\tName: %s\n", menu[i].price, menu[i].name);
    }

    //ask user for sort order type
    sort_order userChoice = read_choice();
    switch(userChoice){
        case byName:
            qsort(menu, count, sizeof(menu_item), char_comparator);
            break;
        case byPrice:
            qsort(menu, count, sizeof(menu_item), int_comparator);
            break;
        default:
            printf("Sort not defined.\n");
            break;
    }

    //Print the list after sorting
    printf("Sorted array: \n");
    for (int i = 0; i<count; i++){
        printf("Price:%8.2lf\tName: %s\n", menu[i].price, menu[i].name);
    }

    return 0;
}
void read_string(char *str) {
    fgets(str, LINE_SIZE, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}
sort_order read_choice(void){
    sort_order choice;
    char input[20];
    int invalid_input;
    do{
        printf("Enter 'byName' or 'byPrice' to sort the list: ");
        fgets(input, 20, stdin);
        printf("input: %s\n", input);
        if(input[strlen(input)-1] =='\n'){
            input[strlen(input)-1]= '\0';
        }
        if(strcmp(input, "byName")==0){
            invalid_input=0;
            choice = byName;
        }else if(strcmp(input, "byPrice")==0){
            invalid_input=0;
            choice = byPrice;
        }else{
            invalid_input = 1;
        }
    }while(invalid_input==1);

    return choice;
}

int int_comparator(const void *a, const void *b){
    int ca= ((menu_item *)a)->price;
    int cb= ((menu_item *)b)->price;
    if(ca<cb){
        return -1;
    }else if (ca>cb){
        return 1;
    }else{
        return 0;
    }
}
int char_comparator(const void *a, const void *b){
    char ca[50];
    char cb[50];
    strcpy(ca, ((menu_item *)a)->name);
    strcpy(cb, ((menu_item *)b)->name);
    return strcmp(ca, cb);
}