#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

//This will be the main ui file

int main()
{
  printf("'~' to exit");
  while(1){
    
    char str[50];
    printf("\n\n> ");
    scanf(" %[^\n]",str);
    if(str[0]=='~'){
      printf("Goodbye.\n");
      goto done;
    }
    char **tokens = (tokenize(&str[0]));
    print_tokens(tokens);
    free_tokens(tokens);
  }
 done: // To exit from program
  return 0;
}
