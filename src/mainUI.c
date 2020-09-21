#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

//This will be the main ui file

int main()
{
  int hCnt = 0; //keeps track of how many items in history
  List *history = init_history();
  while(1) {   
    char str[50];
    printf("\n\n> ");
    scanf(" %[^\n]", str);  
    if(str[0] == '~') {   //Escape character ends program
      printf("Goodbye.\n");
      goto done;
    }
    else if(str[0] == '!') {  //signals an attempt to retrieve from history
      char *end;
      long rid = strtol(&str[1], &end, 10);  //converts string to long
      if(rid > hCnt) {  //checks that requested id exists in history
	printf("Enter a valid ID to retrieve string from history\nItems in history: %d", hCnt);
      }
      else {
	char *hist = get_history(history, (int) rid);
	char **tokens = (tokenize(hist));
	print_tokens(tokens);
	free_tokens(tokens);
      }
    }
    else if(str[0] == '?') {   //signals display history request
      print_history(history);
    }
    else {  //new string input to tokenize
      char *temp = word_start(&str[0]);
      int len = 0;
      while(*temp != '\0') { // determines string length
	len++;
	temp++;
      }
      char *strCopy = malloc(sizeof(char) * (len + 1));  //allocates memory for copy of string
      temp = temp - len;
      while(*temp != '\0') {  //copy string to allocated memory
	*strCopy = *temp;
	strCopy++;
	temp++;
      }
      *strCopy = *temp;
      strCopy = strCopy - len;
      hCnt++;
      add_history(history, strCopy);
      char **tokens = (tokenize(strCopy));
      print_tokens(tokens);
      free_tokens(tokens);  //free tokens imediately after printing
    }
  }
 done: // Exit program
  free_history(history);  //free history before exiting program
  return 0;
}
