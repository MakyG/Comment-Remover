/**
 * @file       functions.c
 * @author     Makyča Tomáš
 * @date       26. 2. 2020
 * @brief      Implementation of function.h header file
 * ******************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/*Private includes: ---------------------------------------------------------*/
#include "functions.h"

/*Class definition: ---------------------------------------------------------*/

FILE* Functions_LoadStream(streamType type, int argc, char** argv) {
 FILE *file = NULL;

 if (type == _IN) {
    if (argc > 1 && argv[1] != NULL)
        file = fopen(argv[1], "r");
    else
        file = stdin;
 }
 else if (type == _OUT) {
     if (argc > 2 && argv[2] != NULL)
         file = fopen(argv[2], "w");
     else
         file = stdout;
 }

  return file;
}

void Functions_RemoveNotes(FILE* input, FILE* output) {
    if (!input || !output)
        return;

    enum { start, slash, doubleSlash, backSlashQ, backSlashS, qoute, simpleQoute, multiLine, multiLineE } state = start;
    char ch;

    while((ch = (char)fgetc(input)) != EOF) {
        switch (state) {

        case start:

            if (ch == '/') {
                state = slash;
                continue;
            }
            else if (ch == '"')
                state = qoute;
            else if (ch == '\'')
                state = simpleQoute;

            fputc(ch, output);
            break;

       case slash:

            if (ch == '/')
                state = doubleSlash;
            else if (ch == '*')
                state = multiLine;
            else {
                state = start;
                fputc('/', output);
                fputc(ch, output);
            }
            break;

       case doubleSlash:

            if (ch == '\n')
            {
                fputc(ch, output);
                state = start;
            }
            break;

       case qoute:

            if (ch == '"')
               state = start;
            else if (ch == '\\')
               state = backSlashQ;
            fputc(ch, output);
            break;

        case simpleQoute:

            if (ch == '\'')
               state = start;
            else if (ch == '\\')
               state = backSlashS;
            fputc(ch, output);
            break;

        case multiLine:

            if (ch == '*')
                state = multiLineE;
            break;

        case multiLineE:

            if (ch == '/')
                state = start;
            else
                state = multiLine;
            break;

        case backSlashQ:

            fputc(ch, output);
            state = qoute;
            break;

        case backSlashS:

            fputc(ch, output);
            state = simpleQoute;
            break;
        }
    }
}
