#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  int hCnt = 0; /* Keeps track of how many items in history */
  List *history = init_history();
  printf("\n\nTokenizer commands:\n'?' \t- View history\n'!<ID>'\t- Tokenize item from history\n'~' \t- Exit");
  while(1) {   
    char str[50];
    printf("\n\n> ");
    scanf(" %[^\n]", str);  
    if(str[0] == '~') {   /* Exits program */
      printf("Goodbye.\n");
      goto done;
    }
    else if(str[0] == '!') {  /* Signals an attempt to retrieve from history */
      char *end;
      long rid = strtol(&str[1], &end, 10);  /* Converts string to long */
      if(rid > hCnt) {  /* Checks that requested id exists in history */
	printf("Enter a valid ID to retrieve string from history\nItems in history: %d", hCnt);
      }
      else {
	char *hist = get_history(history, (int) rid);
	char **tokens = (tokenize(hist));
	print_tokens(tokens);
	free_tokens(tokens);
      }
    }
    else if(str[0] == '?') {   /* Signals display history request */
      print_history(history);
    }
    else {  /* New string input to tokenize */
      char *strCopy = copy_str_hist(&str[0]);
      hCnt++;
      add_history(history, strCopy);
      char **tokens = (tokenize(strCopy));
      print_tokens(tokens);
      free_tokens(tokens);  /* Free tokens imediately after printing */
    }
  }
 done: /* Exit program */
  free_history(history);  /* Free history before exiting program */
  return 0;
}
