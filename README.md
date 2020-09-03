#  Zpracování textů - konečný automat #
Naprogramujte **konečný Mealyho automat**, který ze vstupního souboru v jazyce C/C++ odstraní poznámky (tzn. vše mezi znaky /* */ nebo // \n).

## Ošetření vstupů ##
- puts("Toto je řetězec //a toto ani /* toto */ neni poznámka");
- putchar('"'); /* Toto byl znak uvozovky, ne řetězec. Takže toto je poznámka */
- backslash: puts ("Toto \" je stále řetězec"); // to samé platí i pro znakové konstanty  v apostrofech: _'\''_

## Vstup programu ##
- soubor zadaný jako 1. parametr na příkazové řádce
- standardní vstup (stdin), pokud parametr není zadán

## Výstup programu ##
- do souboru, který byl zadán jako 2. parametr na příkazové řádce
- na standardní výstup (stdout), pokud 2. parametr není zadán

Pokud je na příkazové řádce pouze 1 parametr, bere se tento parametr jako jméno vstupního souboru.

V adresáří test_files najdete vzorový výstup.


---
#  Text processing - finite automaton #
Program **finite Mealy automaton**, which removes the notes (ie everything between / * * / or // \ n) from the C / C ++ input file.

## Input treatment ##
- puts ("This is // and this or /* this */ is not a comment"); 
- putchar ('"'); /* This was a quotation mark, not a string. So this is a note */
- backslash: puts ("This \" is still a string "); // the same applies to character constants in apostrophes: _'\''_

## Program input ##
- File specified as the 1st parameter on the command line
- standard input (stdin) if parameter is not specified

## Program output ##
- to a file that was specified as the second command line parameter
- to standard output (stdout) if parameter 2 is not specified

If there is only one parameter on the command line, it is taken as the name of the input file.

You can find sample output in the test_files directory.

