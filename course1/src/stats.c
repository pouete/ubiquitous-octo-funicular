/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats,c
 * @brief Implementation of stats.h
 *
 * This file implementes stats.h and give some usage exemples.
 * sort_array have been implemented using an in place quicksort algorithm.
 * It's memory footprint is thus reduced to the mimmum.
 * Compilation :
 * gcc -o stats.out stats.c
 * Compatibility : Linux terminals only
 *
 * @author Juilen Godin
 * @date 28/10/2017
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
/* Define nice colors for the linux terminal */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  unsigned char *pointer_to_test;
  /* Other Variable Declarations Go Here */
  /* To avoid any other warnings, cast the array now.*/
  pointer_to_test = &test;

  /* Statistics and Printing Functions Go Here */
  sort_array(pointer_to_test,SIZE);
  printf("%sThis is the sorted array:%s\n",KRED,KNRM);
  print_array(pointer_to_test,SIZE);
  print_statistics(pointer_to_test,SIZE);

}

unsigned char print_statistics(unsigned char *array, unsigned int array_size){

    printf("%smedian%s value is:  %s%d\n", KGRN, KNRM, KRED, find_median(array,array_size));
    printf("%smean%s value is:    %s%d\n", KGRN, KNRM, KRED, find_mean(array,array_size));
    printf("%smaximum%s value is: %s%d\n", KGRN, KNRM, KRED, find_maximum(array,array_size));
    printf("%sminimum%s value is: %s%d\n", KGRN, KNRM, KRED, find_minimum(array,array_size));
    //reset the terminal
    printf("%s\n", KNRM);
}

unsigned char print_array(unsigned char *array, unsigned int array_size){
    unsigned int i;
    for ( i = 0; i < array_size; i++){
        printf("Array value at position %d is %d\n",i,array[i]);
    }
    return 0;
}

unsigned char find_median(unsigned char *sorted_array, unsigned int array_size){
    if(array_size % 2 == 0 )  {
        return ((sorted_array[array_size/2] + sorted_array[array_size/2 -1]) / 2);
    }else{
        return sorted_array[array_size/2];
    }

}

unsigned char find_mean(unsigned char *array, unsigned int array_size){
    unsigned int i;
    unsigned int sum = 0;
    for ( i = 0; i < array_size; i++){
        sum += array[i];
    }
    return sum/array_size;
}

unsigned char find_maximum(unsigned char *sorted_array, unsigned int array_size){
    return sorted_array[0];
}

unsigned char find_minimum(unsigned char *sorted_array, unsigned int array_size){
    return sorted_array[array_size-1];
}

unsigned char sort_array(unsigned char *array, unsigned int array_size){
    if (array_size < 2) return 0;

    int pivot = array[array_size / 2];

    int i, j;
    for (i = 0, j = array_size - 1; ; i++, j--) {
        while (array[i] > pivot) i++;
        while (array[j] < pivot) j--;

        if (i >= j) break;

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    sort_array(array, i);
    sort_array(array + i, array_size - i);

    return 0;
}


