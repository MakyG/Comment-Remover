/**
 * @file       functions.h
 * @author     Horak
 * @date       2019.6
 * @brief      Header file defining functions for functions.c file
 * ******************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

/*Private includes: ---------------------------------------------------------*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Private defines: ----------------------------------------------------------*/
typedef enum { _IN, _OUT } streamType;

/**
 * @brief Loads file/stdin/stdout for input/output depending on input arguments
 * @param[in] type      Enum defining if file is for input or output
 * @param[in] argc      Number of arguments:
 * (0 - both from std, 1 - in from file, out to std, 2 - both from file)
 * @param[in] argv      Array with input arguments:
 * @return              Returns file with file/stdin/stdout to input/output
 */
FILE* Functions_LoadStream(streamType type, int argc, char** argv);

/**
 * @brief Mealys automat - takes line from input file, check for defined rules
 * then outputs result to output file
 * @param[in] input         Code loaded from file or stdin
 * @param[out] output       Outputs code without notes into file or stdout
 */
void Functions_RemoveNotes(FILE* input, FILE* output);

#endif
