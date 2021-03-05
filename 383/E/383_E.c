/*
  Athr: Bitcario
  Prog: Necklace Matching 
  Desc: See Wiki entry
  Date: 11.30.2020
  Note: Challenge and bonus part 1.
*/

// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Macros 
#define BUF_LEN 256
// Function Prototypes
bool
SameNecklace(char *src, char *shifted);

size_t
Repeats(char *str);

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
  FILE *snFile;
  FILE *repFile;

  // Set up
  snFile = fopen("./same_necklace.txt", "r");
  repFile = fopen("./repeats.txt", "r");
  //enFile = fopen("./enable1.txt");

  // Input and processing
  while (fgets(input, BUF_LEN, snFile))
  {
    strcpy(srcStr, "\0");
    strcpy(shiftedStr, "\0");
    sscanf(input, "\"%[^\"]\", \"%[^\"]", srcStr, shiftedStr);
    printf("%s: %s\n", prog, SameNecklace(srcStr, shiftedStr) ? "true" : "false");
  }

  strcpy(input, "\0");
  while (fgets(input, BUF_LEN, repFile))
  {
    strcpy(srcStr, "\0");
    sscanf(input, "\"%[^\"]\"", srcStr);
    printf("%s: \"%s\" repeats: %lu\n", prog, srcStr, Repeats(srcStr));
  }

  // Clean up
  fclose(snFile);
  fclose(repFile);

  return EXIT_SUCCESS;
}

bool
SameNecklace(char *src, char *shifted)
{
  if (!src || !shifted 
      || strlen(shifted) != strlen(src))
  {
    return false;
  }

  if (strcmp(shifted, "") == 0)
  {
    return true;
  }
  
  char searchStr[BUF_LEN * 2];

  memset(searchStr, '\0', sizeof(searchStr));
  strcpy(searchStr, shifted);
  strcat(searchStr, shifted);

  return strstr(searchStr, src) ? true : false;
}

size_t
Repeats(char *str)
{
  if (!str)
  {
    return 0;
  }

  if (strlen(str) == 0)
  {
    return 1;
  }
  
  char searchStr[BUF_LEN * 2];
  size_t strLen;
  size_t count;
  
  strLen = strlen(str);
  count = 0;
  memset(searchStr, '\0', sizeof(searchStr));
  strcpy(searchStr, str);
  strcat(searchStr, str);
 
  for (size_t i = 0; i < strLen; i++)
  {
    count += strnstr(searchStr + i, str, strLen) ? 1 : 0;
  }

  return count;
}
