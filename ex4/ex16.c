//
// Created by Hanh Hoang on 25.9.2023.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
} nnode;

bool read_nr(nnode **head, nnode **tail, int *count);
int main(){
    nnode *head = NULL;
    nnode *tail = NULL;
    int count = 0;
    bool end_program = false;
    while(!end_program){
        end_program= read_nr(&head, &tail, &count);
    }
    //Print the numbers in nodes
    printf("Print %d numbers in nodes: \n", count);
    nnode *current_node = head;
    while(current_node!= NULL){
        printf("%d ->",current_node->number);
        nnode *temp = current_node;
        current_node = current_node->next;
        free(temp);
    }
    return 0;
}

bool read_nr(nnode **head, nnode **tail, int *count){
    char input[10];
    bool valid_number = true;
    bool end_program = false;
    printf("Enter numbers or enter 'end' to stop entering numbers: ");
    fgets(input, 10, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    printf("Input is %s\n", input);

    int i=0;
    while(input[i]!= '\0'){
        if(!isdigit(input[i])){
            valid_number = false;
            break;
        }
        i++;
    }
    if(valid_number == false){
        if(strcmp(input, "end")==0){
            end_program = true;
        }else{
            printf("Invalid input\n");
        }
    }else{
        int nr = atoi(input);
        printf("Integer value of string is %d\n", nr);
        nnode *item = (nnode *) malloc(sizeof(nnode));
        if(item == NULL){
            printf("Memory allocation failed\n");
            end_program=true;
        }else{
            ++(*count);
            item->number = nr;
            item->next = NULL;
            if(*head==NULL){
                *head = item;
            }else{
                nnode *this = *head;
                while(this->next!=NULL){
                    this = this->next;
                }
                this->next = item;
            }
        }
    }
    return end_program;

}