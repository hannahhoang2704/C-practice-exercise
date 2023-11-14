//
// Created by Hanh Hoang on 14.11.2023.
//
//PRINT BINARY NUMBERS
//Implement a function that takes two parameters: a number to print and field width. The function prints the number in binary with the specified field width filling the field with leading zeros if necessary. If printing requires more space than the field width specifies the number is still printed in full. The function must not print any white space before or after the number.
//
//For example:
//
//print_binaryw(5, 4) prints 0101
//
//print_binaryw(0x27, 4) prints 100111
//
//print_binaryw(5, 0) prints 101
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>



void print_binaryw(uint32_t value, uint32_t width) {
    int binary_nr[32];
    int i = 0;
    while (value > 0) {
        binary_nr[i] = value % 2;
        value = value / 2;
        i++;
    }
    if (i >= width) {
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binary_nr[j]);
        }
    } else {
        int filled_nr = width - i;
        int filled = 0;
        for (int a = 0; a < filled_nr; a++) {
            printf("%d", filled);
        }
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binary_nr[j]);
        }
    }
}