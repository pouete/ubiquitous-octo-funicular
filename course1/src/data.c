/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Rediptribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file data,c
 * @brief Implementation of data.h
 *
 * This file implementes stats.h and give some usage exemples.
 * sort_array have been implemented using an in place quicksort algorithm.
 * It's memory footprint is thus reduced to the mimmum.
 * Compilation :
 * gcc -o data.o data.c
 * Compatibility : Linux terminals only
 *
 * @author Juilen Godin
 * @date 28/10/2017
 *
 */



#include "data.h"
#include "memory.h"
#include <stdbool.h>


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    uint8_t i = 0;
    uint8_t isNegative = 0;
    if(data == 0){
        *ptr = '0';
        *(ptr + 1 ) = '\0';
        return 2;
    }

    if( data < 0){
        data = -data;
        isNegative = 1;
    }
    while (data != 0 ){
        uint8_t rem = data % base;
        *(ptr + i++) = ( rem > 9)? (rem -10) + 'a' : rem + '0';
        data = data/base;
    }
    if( isNegative ){
        *(ptr + i++) = '-';
    }
    *(ptr + i++) = '\0';

    my_reverse(ptr,i-1);
    return i;
}



int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    uint32_t res = 0; // Initialize result
      // Iterate through all characters of input string
    uint8_t isNegative = (*ptr == '-')? 1:0 ;

    for (uint8_t i=isNegative;i< (digits - 1); ++i){
        res = res*base + ((*(ptr + i) > '9') ? *(ptr + i)+ 10 - 'a': *(ptr + i) -'0');
    }

    if(isNegative){
        res = ~(int32_t) res +1;
    }
    return res;

}
