/*
 * Athr: https://github.com/Bitcario
 * Nmbr: 361
 * Diff: Easy
 * Prog: Tally 
 * Desc: https://github.com/Bitcario/Daily-Programmer/wiki/361_E 
 * Date: 05.19.2018
 * Note: None.
 */

// Header Files
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

// Macros
#define BUF_LEN 256

// main()
int 
main(int argc, char **argv)
{
  // Administrative
  const char * const prog = argv[0]; 

  // Declarations & Initializations 
  char  input[BUF_LEN];
  char  tallyOrder[] = "abcde";
  int   inputLen;
  int   tallyCnt[5];
  
  // Input
  while (fgets(input, BUF_LEN, stdin))
  {
    if (strcmp(input, "") == 0)
    {
      fprintf(stderr, "%s: Error, empty string.\n", prog);
      return EXIT_FAILURE;
    } 

    // Process 
    memset(tallyCnt, 0, 5*sizeof(int));
    strcpy(tallyOrder, "abcde");
    inputLen = strlen(input);

    // Tally scores
    for (int i = 0; i < inputLen; i++) 
      tallyCnt[tolower(input[i]) - 'a'] += isupper(input[i]) ? -1 : 1;

    // Order by descending score via bubble sort.
    for (int i = 0; i < 5; i++)
      for (int j = i + 1; j < 5; j++) 
        if (tallyCnt[j] > tallyCnt[i])
        {
          int tempVal;
          int tempLetter;

          tempVal = tallyCnt[i];
          tallyCnt[i] = tallyCnt[j];
          tallyCnt[j] = tempVal;

          tempLetter = tallyOrder[i];
          tallyOrder[i] = tallyOrder[j];
          tallyOrder[j] = tempLetter;
        }
     
    // Output
    printf("%s: ", prog);
    for (int i = 0; i < 5; i++)
    {
      printf("%c: %d ", tallyOrder[i], tallyCnt[i]);
    }
    printf("\n");
  }

  // Fin
  return EXIT_SUCCESS;
}
