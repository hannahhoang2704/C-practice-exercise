//
// Created by Hanh Hoang on 26.9.2023.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define STR_SIZE 32
bool pw_generator(char *p, int max_length, const char *wordP);
void read_string(char *str);
char random_gen_character();
int main(void){
    char word[STR_SIZE];
    char password[STR_SIZE];
    srand(time(NULL));
    read_string(word);
    while(strcmp(word, "stop")!=0){
        if(pw_generator(password, STR_SIZE, word)){
            printf("Generated password is \"%s\"\n", password);
        }else{
            printf("String input is too long to generate a password.\n");
        }
        read_string(word);
    }

    return 0;
}

void read_string(char *str) {
    printf("Enter a word to generate password or 'stop' to stop program: ");
    fgets(str, STR_SIZE, stdin);
//    printf("input string: %s\n", str);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}
char random_gen_character(){
    char ch;
    int r = rand()%130;
    while(isprint(r)==0){
        r = rand()%130;
    }
    ch = r;
//    printf("Random character: %c\n", ch);
    return ch;
}
bool pw_generator(char *p, int max_length, const char *wordP){
    bool pw_generated = true;
    int pw_length = strlen(wordP) *2 +1 +1; //1 for NULL character
    printf("length of word %lu and length of pw include NULL is %d\n", strlen(wordP), pw_length);
    if(pw_length>max_length){
        pw_generated=false;
        return pw_generated;
    }
    p[0]= random_gen_character();
    int w_index= 0;
    for(int i = 1; i<pw_length-2; i+=2){
        p[i] = wordP[w_index];
        p[i+1]= random_gen_character();
        w_index++;
    }
    p[pw_length-2]= random_gen_character();
    p[pw_length-1]= '\0';
    printf("Strlen of word %lu strlen of new pw %lu\n", strlen(wordP), strlen(p));
    return pw_generated;
}