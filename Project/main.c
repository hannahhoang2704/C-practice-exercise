#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

int main() {
    char student_name[STRING_SIZE];
    int subject_nr = 0;
    printf("Welcome to the Student Grade Calculator!\nPlease enter your name: ");
    read_string(student_name,STRING_SIZE);
    subject_nr = read_nr();
    score_record record[subject_nr];

    //Input the subject and its score to record array
    for(int i = 0; i<subject_nr; ++i){
        char subject_name[STRING_SIZE];
        printf("Enter subject %d name: ", i+1);
        read_string(subject_name, STRING_SIZE);
        strcpy(record[i].subject_name, subject_name);
        record[i].score = read_score(MIN_SCORE, MAX_SCORE, subject_name);
        record[i].grade = calculate_grade(record[i].score);
    }

    //write to the file
    FILE *my_file;
    my_file = fopen(FILE_NAME, "w");
    if(my_file==NULL){
        fprintf(stderr, "\"%s\" can not be opened.\n", FILE_NAME);
        return -1;
    }else {
        display_record(my_file,student_name, record, subject_nr);
        fclose(my_file);
    }
    
    //print to console
    display_record(stdout,student_name, record, subject_nr);

    return 0;
}

void read_string(char *str, int size){
    fgets(str, size, stdin);
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }else{
        while(getchar()!='\n');
    }
}

int read_nr(){
    int nr;
    bool valid_input = false;
    do{
        printf("How many subjects do you want to calculate grades for? ");
        if (scanf("%d", &nr)!=1){
            while (getchar() != '\n');
            printf("Invalid input. Input must be an positive integer.\n");
        }else if(nr <0){
            printf("Input a positive integer.\n");
        }else{
            valid_input = true;
        }
    }while(nr < 0 || valid_input==false);
    while(getchar()!='\n');
    return nr;
}

int read_score(int low, int high, char *subject){
    int score;
    bool valid_input = false;
    do{
        printf("Enter your score for %s (%d-%d): ", subject, low, high);
        if(scanf("%d", &score) != 1){
            while (getchar()!= '\n');
            printf("Invalid input. Enter score in a range between %d and %d\n", low, high);
        }else if(score < low || score>high){
            printf("Score should be in range between %d and %d\n", low, high);
        }else{
            valid_input = true;
        }
    }while(score<low || score>high || valid_input == false);

    while(getchar()!='\n');

    return score;
}

int calculate_grade(int score){
    int grade = 0;
    if(score >= A_SCORE_THRESHOLD && score <= MAX_SCORE){
        grade = A_GRADE;
    }else if(score >= B_SCORE_THRESHOLD){
        grade = B_GRADE;
    }else if(score >= C_SCORE_THRESHOLD){
        grade = C_GRADE;
    }else if(score >= D_SCORE_THRESHOLD){
        grade = D_GRADE;
    }else if(score >= E_SCORE_THRESHOLD){
        grade = E_GRADE;
    }else{
        grade = F_GRADE;
    }
    return grade;
}

void display_record(FILE *stream, const char *name, const score_record *record, int subject_nr){
    char border[]= "--------------------------------------------------------------------------";
    int sum = 0;

    fprintf(stream, "%s\n", border);
    fprintf(stream, "Student: %s\n", name);
    fprintf(stream, "%s\n", border);
    fprintf(stream, "%-*s %*s %*s\n", TEXT_ALIGNMENT1, "Subject", TEXT_ALIGNMENT2, "Score", TEXT_ALIGNMENT2, "Grade");
    fprintf(stream, "%s\n", border);

    for(int j=0; j<subject_nr; ++j){
        sum += record[j].grade;
        fprintf(stream, "%-*s %*d %% %*d\n", TEXT_ALIGNMENT1, record[j].subject_name, NR_ALIGNMENT, record[j].score, NR_ALIGNMENT, record[j].grade);
    }

    fprintf(stream, "\nAverage score: %.2lf\n", (double)sum/subject_nr);
    fprintf(stream, "%s\n", border);

}
