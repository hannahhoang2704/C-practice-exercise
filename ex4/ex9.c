//
// Created by Hanh Hoang on 4.9.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARRAY_SIZE 20

int find_first(const unsigned int *array, unsigned int what);
void get_array_nr(unsigned int *array, int max_nr);
int read_choice();

int main(){
    unsigned int search_array[ARRAY_SIZE];
    int search_nr;
    //random array
    get_array_nr(search_array, ARRAY_SIZE);

    search_nr = read_choice();

    while(search_nr != 0){
        int result;
        result = find_first(search_array, search_nr);
        if(result == -1){
            printf("Not found\n");
        }else{
            printf("Number %d is firstly found at index %d\n", search_nr, result);
        }
        search_nr = read_choice();
    }

    return 0;
}

void get_array_nr(unsigned int *array, int max_nr){
    srand(time(NULL));
    for(int i = 0; i < (max_nr-1); i++){
        array[i] = 1 + rand()/((RAND_MAX + 1u)/max_nr);
        printf("%d\n", array[i]);
    }
    array[max_nr-1] = 0;
    printf("%d\n", array[max_nr-1]);
}

int read_choice(){
    int choice;
    int valid_number = 0;
    do{
        printf("Enter number to search for or zero to stop: ");
        if (scanf("%d", &choice)!=1){
            while (getchar() != '\n');
            printf("Invalid input\n");
        }else{
            valid_number = 1;
        }
    }while(valid_number == 0);
    return choice;
}
int find_first(const unsigned int *array, unsigned int what){
    int i = 0;
    while(array[i] != 0){
        if(array[i] == what){
            return i;
        }
        i++;
    }
    return -1;
}