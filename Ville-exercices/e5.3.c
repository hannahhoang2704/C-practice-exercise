//
// Created by Hanh Hoang on 14.11.2023.
//
//SORT WITH QSORT()
//Assume the following declarations:
//
//#define MAX_LEN 32
//
//typedef struct student_ {
//    char name[MAX_LEN];
//    int group;
//    int id;
//} student;
//
//typedef enum { byGroup, byLastName, byFirstName } sort_order;
//
//void sort_students(student *students, int count, sort_order sb);
//
//
//Implement function sort_students.
//
//First parameter is array of students.
//Second parameter is number of studenst to sort from the beginning of the array. If zero or negative value is given then all student should be sorted. The end of array marker has id set to zero (id==0).
//Third parameter is the sort criteria.
//Sort_students must use qsort() from standard library to sort the
//
//The sort criterias are:
//
//byGroup :Compare group numbers
//        byFirstName : First name comes first in the string and is separated from the last name by space
//byLastName : As above but comparison must find last name from the strings and compare them

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
} student;

typedef enum { byGroup, byLastName, byFirstName } sort_order;

void sort_students(student *students, int count, sort_order sb);

int int_comparator(const void *a, const void *b){
    int ca= ((student *)a)->group;
    int cb= ((student *)b)->group;
    if(ca<cb){
        return -1;
    }else if (ca>cb){
        return 1;
    }else{
        return 0;
    }
}
int fn_cmp(const void *a, const void *b){
    char ca[MAX_LEN];
    char cb[MAX_LEN];
    strcpy(ca, ((student *)a)->name);
    strcpy(cb, ((student *)b)->name);
    return strcmp(ca,cb);
}

int ln_cmp(const void *a, const void *b){
    char ca[MAX_LEN];
    char cb[MAX_LEN];
    strcpy(ca, ((student *)a)->name);
    strcpy(cb, ((student *)b)->name);

    char *ptrA = strchr(ca, ' ');
    if(ptrA!=NULL){
        ptrA+=1;
        strcpy(ca, ptrA);
    }
    char *ptrB = strchr(cb, ' ');
    if(ptrB!=NULL){
        ptrB+=1;
        strcpy(cb, ptrB);
    }
    return strcmp(ca, cb);
}

void sort_students(student *students, int count, sort_order sb){
    int student_nr = 0;
    if(count<=0){
        while(students[student_nr].id!=0){
            ++student_nr;
        }
        count = student_nr;
    }
    switch(sb){
        case byGroup:
            qsort(students, count, sizeof(student),int_comparator);
            break;
        case byFirstName:
            qsort(students, count, sizeof(student),fn_cmp);
            break;
        case byLastName:
            qsort(students, count, sizeof(student),ln_cmp);
            break;
        default:
            break;
    }
}
