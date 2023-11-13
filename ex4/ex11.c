//
// Created by Hanh Hoang on 11.9.2023.
//
#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl);

int main(void){
    int count;
    char text[80] = "I am so tired of C. Python is much better language";
    count = replace_char(text, "e3");
    if(count == 0){
        printf("String was not modified.\n");
    }else{
        printf("Modified string: \"%s\" and modified number is %d", text, count);
    }
    return 0;
}

int replace_char(char *str, const char *repl){
    int result = 0;
    if(strlen(repl)!= 2){
        printf("Replace string should have only 2 characters\n");
        return result;
    }else{
        for(int i = 0; str[i] != '\0'; ++i){
            if(str[i]==repl[0]){
                str[i] = repl[1];
                result++;
            }
        }
    }
    return result;
}