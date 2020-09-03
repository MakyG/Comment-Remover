/**
 * @file       main.c
 * @author     Horak
 * @date       2019.6
 * @brief      Main file for task11/PME-Notes_Remover.
 * ******************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/*Private includes: ---------------------------------------------------------*/
#include "functions.h"

int main(int argc, char* argv[]) {
  // Loads input/output from arguments or stdin/stdout into file streams
  FILE* input = Functions_LoadStream(_IN, argc, argv);
  FILE* output = Functions_LoadStream(_OUT, argc, argv);

  // Checks if files were loaded correctly
  if (input != NULL && output != NULL) {
    Functions_RemoveNotes(input, output);

    // Closes input/output streams
    fclose(input);
    fclose(output);
  } else
    printf("Input or output was not defined properly\n");

  if (input == NULL) {
    printf("Input failed\n");
  }
  if (output == NULL) {
    printf("Output failed\n");
  }

  return 0;
}
