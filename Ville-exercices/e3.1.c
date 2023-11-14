//
// Created by Hanh Hoang on 14.11.2023.
//
//SORT THREE NUMBERS USING POINTERS
//Write a function that takes three integer pointers as parameters. The function sorts the three numbers in ascending order.
//The prototype of the function is:
//void sort3(int *a, int *b, int *c);
//For example if we have following:
//int n1 = 5;
//int n2 = 3;
//int n3 = 9;
//sort3(&n1, &n2, &n3);
//printf("%d, %d, %d", n1, n2, n3);
//The program prints: 3, 5, 9

void sort3(int *a, int *b, int *c){
    int temp;
    if(*a<*b && *a<*c){
        *a = *a;
        if (*b<*c) {
            *b=*b;
            *c=*c;
        }else{
            temp=*c;
            *c=*b;
            *b=temp;
        }
    }else if (*b<*a && *b<*c){
        if(*a<*c){
            temp=*a;
            *a = *b;
            *c= *c;
            *b= temp;
        }else{
            temp=*a;
            *a = *b;
            *b= *c;
            *c= temp;
        }
    }else if (*c<*a && *c<*b){
        temp = *a;
        if(*a<*b){
            *a= *c;
            *c= *b;
            *b= temp;
        }else{
            *a= *c;
            *b= *b;
            *c= temp;
        }
    }
}

