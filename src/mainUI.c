#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

//This will be the main ui file

int main()
{
  /*char str[50];
  printf("\n> ");
  scanf("%[^\n]",str);
  printf("%s\n",str);
  */

  while (1) { // Infinite while loop

    fputs("\n> ", stdout);
    fflush(stdout);/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)     /* terminate on end-of-file */
      goto done;
    
    if(c=='~'){
      puts("Bye!");
      goto done; /* terminate */
    }
    else{
      printf("sc : %d",space_char(c));
      printf("\nnsc: %d\n",non_space_char(c));
    }
}
 done: // To exit from program
  return 0;
}
