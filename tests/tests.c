/**
 * @file       tests.c
 * @author     Horak
 * @date       2019.6
 * @brief      Unit tests for inplementation of functions in functions.c file
 * ******************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/*Private includes: ---------------------------------------------------------*/
#include <inttypes.h>
#include "../src/functions.h"
#include "minunit.h"

////////////////////////////// IMPORTANT //////////////////////////////////////
/////////// Source repository: https://github.com/siu/minunit /////////////////
/////////// For more info consult with this page //////////////////////////////

static char** arguments;

int CompareFile(FILE* fPtr1, FILE* fPtr2, int* line, int* col);

MU_TEST(test_LoadStream_InputOutputFile)
{
    FILE* input = NULL;
    FILE* output = NULL;

    input = Functions_LoadStream(_IN, 2, arguments);
    if (arguments[3])
      output = Functions_LoadStream(_OUT, 2, arguments);
    else
      output = tmpfile();

    mu_assert(input != NULL, "Input (file) was not loaded properly");
    mu_assert(output != NULL, "Output (file) was not loaded properly");

    if (input != NULL) fclose(input);
    if (output != NULL) fclose(output);
}

MU_TEST(test_LoadStream_InputFileOutputStd)
{
    FILE* input = NULL;
    FILE* output = NULL;
    char* emptyArray[3] = {""};

    input = Functions_LoadStream(_IN, 1, arguments);
    output = Functions_LoadStream(_OUT, 1, emptyArray);

    mu_assert(input != NULL, "Input (file) was not loaded properly");
    mu_assert(output != NULL, "Output (stdout) was not loaded properly");

    if (input != NULL) fclose(input);
    if (output != NULL) output = NULL;
}

MU_TEST(test_LoadStream_InputOutputStd)
{
    FILE* input = NULL;
    FILE* output = NULL;
    char* emptyArray[3] = {""};

    input = Functions_LoadStream(_IN, 0, emptyArray);
    output = Functions_LoadStream(_OUT, 0, emptyArray);

    mu_assert(input != NULL, "Input (stdin) was not loaded properly");
    mu_assert(output != NULL, "Output (stdout) was not loaded properly");

    if (input != NULL) fclose(input);
    if (output != NULL) output = NULL;
}


MU_TEST(test_RemoveNotes) {
  mu_assert(arguments[1], "No argument (input file)");
  mu_assert(arguments[2], "No argument (output file)");

  FILE* input = fopen(arguments[1], "r");
  FILE* output = NULL;
  FILE* exampleOutput = NULL;

  if (arguments[3]) {
    exampleOutput = fopen(arguments[3], "r");
    output = fopen(arguments[2], "w");

    mu_assert(input != NULL, "Input failed");
    mu_assert(output != NULL, "Output failed");

    Functions_RemoveNotes(input, output);

    fclose(output);
    output = fopen(arguments[2], "r");

    int line = 1, col = 0;
    int diff = CompareFile(output, exampleOutput, &line, &col);

    if (diff != 0) {
      printf("\nFiles are not equal.\n");
      printf("Line: %d, col: %d\n", line, col);
    }

    fclose(output);
    fclose(exampleOutput);
  } else {
    printf("\nUnit test file comparing was skipped.");
  }

  fclose(input);
}

int CompareFile(FILE* file1, FILE* file2, int* line, int* col) {
  char ch1 = fgetc(file1);
  char ch2 = fgetc(file2);

  while (ch1 != EOF && ch2 != EOF) {
    if (ch1 == '\n') {
      *line += 1;
      *col = 0;
    }

    if (ch1 != ch2) {
      return -1;
    }

    *col += 1;

    ch1 = fgetc(file1);
    ch2 = fgetc(file2);
  }

  if (ch1 == EOF && ch2 == EOF)
    return 0;
  else
    return -1;
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_LoadStream_InputOutputFile);
  MU_RUN_TEST(test_LoadStream_InputFileOutputStd);
  MU_RUN_TEST(test_LoadStream_InputOutputStd);
  MU_RUN_TEST(test_RemoveNotes);
}

int main(int argc, char* argv[]) {
  (void)argc;
  arguments = argv;
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return 0;
}
