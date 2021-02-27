/*
  Athr: Bitcario
  Prog: Necklace Matching 
  Desc: See Wiki entry
  Date: 11.30.2020
  Note: none
*/

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// User-defined Header Files

// Macros 
#define BUF_LEN 256
// Global Variables

// Data Structures

// Function Prototypes
bool
SameNecklace(char *src, char *shifted);
// Macros

// main()
int 
main(int argc, char** argv)
{
  // Suppress warnings
  const char *prog = argv[argc - argc];

  // Declarations 
  char input[BUF_LEN];
  char srcStr[BUF_LEN];
  char shiftedStr[BUF_LEN];

  // Input
  while (fgets(input, BUF_LEN, stdin))
  {
    strcpy(srcStr, "\0");
    strcpy(shiftedStr, "\0");
    sscanf(input, "\"%[^\"]\", \"%[^\"]", srcStr, shiftedStr);
    printf("%s: %s\n", prog, SameNecklace(shiftedStr, srcStr) ? "true" : "false");
  }

  return EXIT_SUCCESS;
}

bool
SameNecklace(char *src, char *shifted)
{
  if (strcmp(shifted, "") == 0)
    return true;

  if (!src || !shifted 
      || strlen(shifted) != strlen(src))
    return false;
  
  char searchStr[BUF_LEN * 2];

  memset(searchStr, '\0', sizeof(searchStr));
  strcpy(searchStr, shifted);
  strcat(searchStr, shifted);
  return strstr(searchStr, src) ? true : false;
}
