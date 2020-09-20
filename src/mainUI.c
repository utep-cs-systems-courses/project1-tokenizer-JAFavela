#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

//This will be the main ui file

int main()
{
  char *strCopy;
  List *history = init_history();
  printf("'~' to exit");
  while(1){   
    char str[50];
    printf("\n\n> ");
    scanf(" %[^\n]",str);
    if(str[0]=='~'){
      printf("Goodbye.\n");
      goto done;
    }
    else if(str[0]=='!'){
      char *end;
      long rid= strtol(&str[1], &end, 10);
      char *hist = get_history(history, (int) rid);
      if(*hist!='\0'){
	char **tokens = (tokenize(hist));
	print_tokens(tokens);
	free_tokens(tokens);
      }
    }
    else if(str[0]=='?'){
      print_history(history);
    }
    else{
      char *temp=word_start(&str[0]);
      int len= 0;
      while(*temp!='\0'){
	len++;
	temp++;
      }
      strCopy= malloc(sizeof(char)*(len+1));
      temp=temp-len;
      while(*temp!='\0'){
	*strCopy=*temp;
	strCopy++;
	temp++;
      }
      *strCopy=*temp;
      strCopy=strCopy-len;
      add_history(history,strCopy);
      char **tokens = (tokenize(strCopy));
      print_tokens(tokens);
      free_tokens(tokens);
    }
  }
 done: // To exit from program
  free_history(history);
  return 0;
}
