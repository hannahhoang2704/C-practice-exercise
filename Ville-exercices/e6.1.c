//
// Created by Hanh Hoang on 14.11.2023.
//
//DEBUG MESSAGES WITH VARIABLE ARGUMENTS
//Write implementation of function printd that takes same parameters as printf and produces same output as printf but precedes all output with "DEBUG: ". Function returns number of output characters including the debug prefix in the output.
//
//For example, if you call printd("test") then output is "DEBUG: test" and return value is 11.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>


int printd(const char *format, ...) {
    int count;
    va_list argptr;

    va_start(argptr, format);

    printf("DEBUG: ");
    count = vprintf(format, argptr);
    va_end(argptr);
    return count + 7;
}