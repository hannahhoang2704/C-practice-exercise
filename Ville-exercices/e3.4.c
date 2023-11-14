//
// Created by Hanh Hoang on 14.11.2023.
//
//MOVE ELEMENTS BETWEEN ARRAYS OF STRUCTURE
//Assume following declarations and definitions:
//
//#define MAX_LEN 32
//
//typedef struct student_ {
//    char name[MAX_LEN];
//    int group;
//    int id;
//} student;
//
//int move(student *source, int group, student *target, int size);
//
//
//Implement function move() that moves elements from source to target. Second parameter group determines which elements to move. Only the elements of matching group are moved to target array. Both source and target are arrays that are initialized by the caller. The end of array is marked with an element where id is zero.
//
//When you remove elements from the source you must preserve the order of remaining elements and ensure that end marker is in right place. When you add an element to the target remember that you must not add new elements if the target already has (size-1) elements. The target must also have an end marker.
//
//Move returns number of elements moved to the target. Function returns zero if no matching element were found or if the target list is full.

#define MAX_LEN 32

typedef struct student_ {
    char name[MAX_LEN];
    int group;
    int id;
} student;

int move(student *source, int group, student *target, int size) {
    int move_nr = 0;
    int source_index = 0;
    int target_index = 0;
    while(target[target_index].id!= 0){
        ++target_index;
    }
    while (source[source_index].id != 0) {
        if (source[source_index].group == group) {
            if (target_index < size - 1) {
                target[target_index] = source[source_index];

                for (int j = source_index; source[j].id != 0; j++) {
                    source[j] = source[j + 1];
                }
                target_index++;
                move_nr++;
            } else {
                return 0;
            }
        } else {
            source_index++;
        }
    }

    source[source_index].id = 0;
    target[target_index].id = 0;
    return move_nr;
}