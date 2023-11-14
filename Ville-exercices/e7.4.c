//
// Created by Hanh Hoang on 14.11.2023.
//
//CALL FUNCTION AND READER FUNCTION
//Write functions to decode SLIP framed data. See: http://www.tcpipguide.com/free/t_SerialLineInternetProtocolSLIP-2.htm for information about slip.
//
//You need to write two functions:
//
//Function called register_slip_frame_callback that takes one parameter:  pointer to a function that takes a const unsigned char pointer and an integer as parameters and returns no value. register_slip_frame_callback does not return a value. The function stores the callback function pointer to a global variable.
//Function called process_slip_data that takes one parameter: pointer to a function that does not take any parameters and returns an integer. Process_slip_data does not return a value.
//Process_slip_data uses the function given as parameter to read bytes that carry SLIP framed data. The function reads and decodes data until the reader function return EOF to indicate end of input. The data that reader function returns contains SLIP framed data where the maximum data length is 40 bytes. Note that because of escaping the number of received bytes before frame is completetely received can be much longer (82 bytes in the worst case before decoding). The length of decoded data never exceed 40 bytes. When a frame is completely received (SLIP_END received) then data is passed to the callback function for processing. If two SLIP_ENDs are received with no data between them the callback function is not called because there is no data to process.
//
//The test bench first registers a callback function and then calls process_slip_data. Both callback function and reader function are implemented in the test bench.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>


#define SLIP_END 0xC0
#define SLIP_ESC 0xDB
#define SLIP_ESC_END 0xDC
#define SLIP_ESC_ESC 0xDD
typedef void (*SlipFrameCallback)(const unsigned char *data, int length);

static SlipFrameCallback slipFrameCallback = NULL;

void register_slip_frame_callback(SlipFrameCallback callback){
    slipFrameCallback = callback;
}

void process_slip_data(int (*read_data)()){
    enum{
        NORMAL_DATA,
        DATA_ESC
    }state = NORMAL_DATA;

    unsigned char frame[40];
    int frame_cnt = 0;

    /*while(true){
        int character = read_data();
        if(character== EOF){
            break;
        }*/
    int character;
    while ((character = read_data()) != EOF){
        switch(state){
            case NORMAL_DATA:
                if(character==SLIP_END){
                    if(frame_cnt > 0 && slipFrameCallback != NULL) {
                        slipFrameCallback(frame, frame_cnt);
                    }
                    frame_cnt = 0;
                }else if(character == SLIP_ESC){
                    state = DATA_ESC;
                }else{
                    if(frame_cnt < sizeof(frame)) {
                        frame[frame_cnt++] = (unsigned char)character;
                    }
                }
                break;

            case DATA_ESC:
                if (character == SLIP_ESC_END) {
                    if (frame_cnt < sizeof(frame)) {
                        frame[frame_cnt++] = SLIP_END;
                    }
                } else if(character == SLIP_ESC_ESC) {
                    if(frame_cnt < sizeof(frame)) {
                        frame[frame_cnt++] = SLIP_ESC;
                    }
                }
                state = NORMAL_DATA;
                break;
        }

    }

}