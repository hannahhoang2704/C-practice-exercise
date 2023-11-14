//
// Created by Hanh Hoang on 14.11.2023.
//
//LOG PRINTING WITH VARIABLE ARGUMENTS
//Implement two functions:
//
//int log(loglevel level, const char *format, ...); works like printf but prints only when level lower than or equal to global variable log_level. When printing precedes printouts with "LOG[%s]: " where %s is the parameter level printed as a string.
//
//const char *log_level_to_str(loglevel level); returns a constant string corresponding to the level parameter. Note that the string returned may not be a variable that is allocated on the stack.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>

int log_level;  //global variable log_level

typedef enum { logCritical, logWarning, logInfo, logVerbose } loglevel;
// Log levels as strings:  "Critical", "Warning", "Info", "Verbose"
// impelement this function
const char *log_level_to_str(loglevel level);
// implement this function
int log(loglevel level, const char *format, ...);

// this (existing) function sets the global log_level variable
void set_log_level(loglevel level);

const char *log_level_to_str(loglevel level){
    const char *logLevel[]= {"Critical", "Warning", "Info", "Verbose"};
    return logLevel[level];
}

int log(loglevel level, const char *format, ...){
    int count;
    va_list argptr;
    va_start(argptr, format);


    if(level<= log_level){
        printf("LOG[%s]: ", log_level_to_str(level));
        count = vprintf(format, argptr);
    }

    va_end(argptr);
    return count;
}