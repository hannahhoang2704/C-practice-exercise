//
// Created by Hanh Hoang on 14.11.2023.
//
//SHIFT AND MASK UNSIGNED NUMBER
//Write a function that shifts bits to right and masks out unwanted bits. The first parameter of the function is the number to process, the second parameter is number shifts to right, and the last parameter is the number of bits to keep starting from the least significant bit (the rightmost bit). The function returns the result of shift-and-mask operation.
//
//To keep certain number of bits you need to create a mask where the bits that you want to keep are set to one and the rest of the bits are set to zero. Then perform bitwise and between the value and mask. For example to keep four bits from the right the mask is 0xF.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

uint32_t get_bits(uint32_t value, uint32_t shift, uint32_t bits) {
    uint32_t mask = (1u << bits) - 1u; // Create mask with rightmost bits set to 1
    uint32_t result = (value >> shift) & mask; // Perform bitwise AND to keep desired bits
    return result;
}