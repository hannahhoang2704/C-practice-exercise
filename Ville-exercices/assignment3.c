//
// Created by Hanh Hoang on 14.11.2023.
//
//Write a program that fills 5 x 3 array so that first column contain numbers 1-5, second column 6-10 and third column 11-15.
//Note! The program may not print anything. The printing is handled by the test bench.

#include <stdio.h>
#include <string.h>




int main(void) {
    int matrix[5][3];
    int nr = 1;
    for (int col = 0; col < 3; col++) {
        for (int row = 0; row < 5; row++) {
            matrix[row][col] = nr;
            nr++;
        }
    }
    return 0;
}

