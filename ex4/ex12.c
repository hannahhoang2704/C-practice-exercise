//
// Created by Hanh Hoang on 12.9.2023.
//
#include <stdio.h>
#include <string.h>
#define STRING_SIZE 256

int count_words(const char* str, const char *word);
void read_string(char *str);
int main(void){
    char string[STRING_SIZE];
    char word[STRING_SIZE];
    int stop_called;
    int word_count;
    do{
        printf("Enter a string: ");
        read_string(string);
        printf("Enter a word: ");
        read_string(word);
        word_count=count_words(string, word);
        printf("The word \"%s\" appears in \"%s\" %d times\n", word, string, word_count);
        stop_called = strcmp(word, "stop");
    }while(stop_called != 0);

    return 0;
}

void read_string(char *str){
    fgets(str, STRING_SIZE, stdin);
    if(str[strlen(str)-1] =='\n'){
        str[strlen(str)-1]= '\0';
    }
}
int count_words(const char* str, const char *word){
    char *ret;
    int result=0;
    int word_length = strlen(word);
    ret = strstr(str, word);
    while(ret != NULL){
        result++;
        ret+=word_length;
        ret = strstr(ret, word);
    }
    return result;
}