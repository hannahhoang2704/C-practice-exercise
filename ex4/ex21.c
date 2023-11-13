//
// Created by Hanh Hoang on 3.10.2023.
//
#include <stdio.h>
#include <string.h>
#define LINE_SIZE 100
#define LINE_LENGTH 256

void read_string(char *str);

int main(void){
    char file_name[LINE_SIZE];
    char line[LINE_LENGTH];
    FILE *file;
    printf("Enter file's name: ");
    read_string(file_name);
    file = fopen(file_name, "r");
    if(file == NULL){
        fprintf(stderr, "\"%s\" can not be opened\n", file_name);
        return 1;
    }else{
        while(fgets(line, LINE_LENGTH, file)!=NULL){
            if(line[0]=='$' && strchr(line, '*')!=NULL){
                int checksum=0;
                int calc_sum=0;
                char *p;
                p = strchr(line, '*');
                p+=1;
//                printf("%s\n", p);
                if(sscanf(p, "%X", &checksum)==1){
//                    printf("Decimal checksum value: %d %X\n", checksum, checksum);

                    //calculate checksum between '$' and '*'
                    for(int i = 1; line[i]!='*'; ++i){
                            calc_sum ^= line[i];
                    }

//                    printf("Calculated checksum: %d %X\n", calc_sum, calc_sum);
                    if(checksum==calc_sum){
                        printf("[OK] %s\n", line);
                    }else{
                        printf("[FAIL] %s\n", line);
                    }
                }
            }
        }
    }

    return 0;
}
void(read_string)(char *str){
    fgets(str, LINE_SIZE, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}