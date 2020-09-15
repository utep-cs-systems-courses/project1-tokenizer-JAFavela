#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

//This will be the main ui file

int main()
{
  printf("'~' to exit");
  while(1){
    
    char str[50];
    printf("\n> ");
    scanf(" %[^\n]",str);
    if(str[0]=='~'){
      printf("Goodbye.\n");
      goto done;
    }
    printf("%s\n",str);
    printf("The word_start() pointer points to : %c\n",*(word_start(&str[0])));
    printf("The word starts at: %d \nThe word_terminator() pointer is at: %d\n",&str[0],word_terminator(&str[0]));
    printf("Count_words() in string: %d\n",(count_words(&str[0])));
    short ln = word_terminator(&str[0]) - (&str[0]);
    printf("Copy of first word using copy_str(): %s\n",copy_str(&str[0],ln));
  }
  
  /* 
  while (1) { // Infinite while loop

    fputs("\n> ", stdout);
    fflush(stdout); 
    int c;
    while ((c = getchar()) == '\n');
    if (c == EOF)      
      goto done;
    
    if(c=='~'){
      puts("Bye!");
      goto done; 
    }
    else{
      printf("sc : %d",space_char(c));
      printf("\nnsc: %d\n",non_space_char(c));
    }
  }
  */
 done: // To exit from program
  return 0;
}
