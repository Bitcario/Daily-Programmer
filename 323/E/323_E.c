/*
 * Athr: https://github.com/Bitcario
 * Nmbr: 323
 * Diff: Easy
 * Prog: 3SUM 
 * Desc: https://github.com/Bitcario/Daily-Programmer/wiki/323_E 
 * Date: 07.22.2017
 * Note: None.
 */

/***** Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/***** User-defined Header Files *****/
/***** Directives *****/
#define BUF_LEN 256
/***** Global Variables *****/
/***** Data Structures *****/
/***** Function Prototypes *****/
int *Cnvrt2IntArr(char *data, int *len);
/***** Macros *****/

/***** main() *****/
int
main(int argc, char** argv)
{ 
  /***** Administrative *****/
  const char *const prog = argv[argc-argc]; 
  /***** Declarations *****/
  char *inStr = NULL;
  int *data = NULL;
  int dataLen;
  /***** Initializations *****/
  dataLen = 1;
  inStr = malloc(sizeof(char)*BUF_LEN);

  assert(inStr != NULL); 
  /***** Begin *****/
  while (1) { 
    /***** Input *****/
    if (!fgets(inStr, BUF_LEN, stdin)) {
      fprintf(stderr, "%s: no available input\n", prog);
      break;
    } 
    /***** Process *****/
    data = Cnvrt2IntArr(inStr, &dataLen); 
    /***** Output *****/
    // printAll3SUM()
  } 
  
  /***** Cleanup *****/
  free(inStr);
  free(data); 
  inStr = NULL;
  data = NULL; 
  /***** Fin *****/
  return EXIT_SUCCESS;
}

/***** Function Definitions *****/
int *Cnvrt2IntArr(char *str, int *len)
{
  assert(str != NULL);
  assert(len != NULL);

  char *ptr = NULL;
  int *data = malloc(sizeof(int) * 128);
  *len = 0;

  ptr = strtok(str, " ");
  while ((ptr = strtok(NULL, " "))) {
    data[*len] = atoi(ptr);
    (*len)++;
  } 

  return data;
} 
