//
// Created by Hanh Hoang on 14.11.2023.
//
//MOVE ELEMENTS FROM A LINKED LIST TO ANOTHER LINKED LIST
//Assume following declarations and definitions:
//
//#define MAX_LEN 32
//
//typedef struct student_ {
//    char name[MAX_LEN];
//    int group;
//    int id;
//    struct student_ *next;
//} student;
//
//int move(student **source, int group, student **target);
//
//
//Implement function move() that moves elements from source to target. Second parameter, group, determines which elements to move. Only the elements of matching group are moved to target list. Both source and target are linked lists that are initialized by the caller. The end of list is market by setting next pointer of the last element to NULL.
//
//When you remove elements from the source you must preserve the order of remaining elements. When you add an element to the target it must be added at the beginning of the traget list.
//
//Move returns the number of elements moved to the target. Function returns zero if no matching elements were found.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
    struct student_ *next;
} student;

int move(student **source, int group, student **target);

int move(student **source, int group, student **target){
    int count=0;
    while (*source!=NULL){
        if((*source)->group == group){
            student *new = (student *)malloc(sizeof(student));
            if(new == NULL){
                return -1;
            }else{
                strcpy(new->name, (*source)->name);
                new->group = (*source)->group;
                new->id = (*source)->id;
                new->next = NULL;
                if(*target ==NULL){
                    *target = new;
                }else{
                    new->next = *target;
                    *target = new;
                }
                *target = new;

                student *pn = *source;
                *source = (*source)->next;
                //free(pn);
                count++;
            }
        }
        else{
            source = &((*source)->next);
        }
    }
    return count;
}
