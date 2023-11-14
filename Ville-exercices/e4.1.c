//
// Created by Hanh Hoang on 14.11.2023.
//
//PRINT MONTH NAMES
//Write a function that takes two parameters: month number and language. The function returns a const char pointer to the name of the month in given language. If an invalid value is given as a parameter the function returns a pointer to "Error".
//
//Write a function that takes one parameter: language and returns a const char pointer to the name of the language. If an unknown language is given function returns a pointer to "Error".
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>



typedef enum { English, Italian, Spanish } language;
const char *month(int number, language lang);
const char *lang2str(language lang);
const char *month(int number, language lang){
    const char *month[3][12]= {
            {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
            {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"},
            {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"}
    };
    if(number <1 || number >12){
        return "Error";
    }

    switch(lang){
        case English:
            return month[0][number-1];
        case Italian:
            return month[1][number-1];
        case Spanish:
            return month[2][number-1];
        default:
            return "Error";
    }

}
const char* lang2str(language lang) {
    const char *languages[3] = {"English", "Italian", "Spanish"};
    if(lang<0||lang>=3){
        return "Error";
    }
    return languages[lang];
}