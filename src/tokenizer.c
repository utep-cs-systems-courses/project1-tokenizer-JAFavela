#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"



/* Return true (non-zero) if c is a whitespace characer
   ('\t' or' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return c < '!';
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  return c >= '!';
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  for(   ; *str != '\0'; str++) {  //goes until first non-space character
    if(non_space_char(*str)) {
      return (str);
    }
  }
  return str;
} 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  for(   ; *word != '\0'; word++) {  //goes until first space character
    if(non_space_char(*word) && space_char(*(word + 1))) {
      return (word + 1);
    }
  }
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int w = 0;
  for(   ; *str != '\0'; str++) {
    if(space_char(*str)) {
      w++;
    }
  }
  return w + 1;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *copy = malloc(sizeof(char) * (len + 1)); //allocates memory for token
  char *temp = copy;
  while(len > 0) {
    if(non_space_char(*inStr)) {  //copies indicated number of characters
      *temp = *inStr;
      temp++;
      inStr++;
      len--;
    }
    else {
      inStr++;
    }
  }
  *temp = '\0';
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  char *strt, **tokens;
  char *end = str;
  int numWrds = count_words(str);
  tokens = malloc(sizeof(char*) * (numWrds + 1));  //allocates memory for token
  for(int w = 0; w < numWrds; w++) {
    strt = word_start(end);
    end = word_terminator(strt);
    *tokens = copy_str(strt, end-strt);
    tokens++;
  }
  char *lst = malloc(sizeof(char)); //allocates mem and creates 0 token
  *lst = '\0';
  *tokens = lst;
  tokens  = tokens - numWrds;
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  printf("\nTokens:");
  while(**tokens != '\0') {
    printf("\n%s", *tokens);
    tokens++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{
  char **temp = tokens;
  while(**temp != '\0') {
    free(*temp);
    temp++;
  }
  free(*temp);
  free(tokens);
}
