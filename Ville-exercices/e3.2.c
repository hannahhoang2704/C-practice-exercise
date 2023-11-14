#include <string.h>

//
// Created by Hanh Hoang on 14.11.2023.
//

//MERGE WHITE SPACE
//Write a function that converts all white space (tab, cr, lf etc.)  to spaces (' ') and merges spaces so that there is only one space between the words. If the string starts or ends with white space only one leading/trailing space is left in the string.
//
//The prototype of the function is
//
//void merge_whitespace(char *);
//
//Note that you may write any number of helper functions to complete the task. The test bench calls merge_whitespace() with different test strings and will accept code if output matches the reference solution.
//
//Hint: To see the test strings start with a dummy function that does not modify the string passed as parameter.
void merge_whitespace(char *string){
    int previousIsSpace = 0;
    int index=0;
    int len =0;
    int deleted =0;
    len = strlen(string);
    //printf("%s", string);
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i]=='\t' || string[i]=='\r' || string[i]=='\n' || string[i]== ' '){
            if (previousIsSpace==0){
                string[index++] = ' ';
                previousIsSpace = 1;
            }else{
                deleted++;
            }
        }else{
            string[index++] = string[i];
            previousIsSpace = 0;
        }
    }
    string[len-deleted]= '\0';

    //printf("%s", string);
};
