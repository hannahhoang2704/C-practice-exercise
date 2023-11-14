//
// Created by Hanh Hoang on 14.11.2023.
//
//CONTEXT POINTER: TEXT READER
//Implement functions text_reader_init and text_reader_read.
//Text reader_init sets the position to zero and stores the pointer in the context.
//Text_reader_read takes context pointer, buffer and buffer size as parameters. The function copies characters from the text in context, starting from current position, until a line feed is encountered, end of text is reached or buffer is full. If reading stops at a line feed the line feed is copied into string. Text_reader_read returns the number of characters copied to buffer. When end of text has been reached following reads must return a zero.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>


typedef struct {
    const char *text;
    int position;
} text_reader_ctx;


// implement the following two functions
void text_reader_init(text_reader_ctx *ctc, const char *str);
int text_reader_read(text_reader_ctx *ctx, char *buffer, int size);
void text_reader_init(text_reader_ctx *ctc, const char *str){
    ctc->position = 0;
    ctc->text = str;
}

int text_reader_read(text_reader_ctx *ctx, char *buffer, int size){

    int nr =0;
    int text_length = strlen(ctx->text);
    while(ctx->position < text_length && nr < size-1){
        buffer[nr] = ctx->text[ctx->position];
        if(ctx->text[ctx->position] =='\n'){
            nr++;
            ctx->position++;
            buffer[nr]= '\0';
            break;
        }
        nr++;
        ctx->position++;

    }
    buffer[nr] = '\0';
    return nr;
}
