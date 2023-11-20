//
// Created by Hanh Hoang on 10.10.2023.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#define STRING_SIZE 40
#define MIN_SCORE 0
#define MAX_SCORE 100

#define A_SCORE_THRESHOLD 90
#define B_SCORE_THRESHOLD 80
#define C_SCORE_THRESHOLD 70
#define D_SCORE_THRESHOLD 60
#define E_SCORE_THRESHOLD 50

#define A_GRADE 5
#define B_GRADE 4
#define C_GRADE 3
#define D_GRADE 2
#define E_GRADE 1
#define F_GRADE 0

#define TEXT_ALIGNMENT1 40
#define TEXT_ALIGNMENT2 8
#define NR_ALIGNMENT 6

#define FILE_NAME "record.txt"

typedef struct score_record_ {
    char subject_name[STRING_SIZE];
    int score;
    int grade;
}score_record;

void read_string(char *str, int size);
int read_nr();
int read_score(int low, int high, char *subject);
int calculate_grade(int score);
void display_record(FILE *stream, const char *name, const score_record *record, int subject_nr);

#endif //PROJECT_MAIN_H
