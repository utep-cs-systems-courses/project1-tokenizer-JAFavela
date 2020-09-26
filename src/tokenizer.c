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
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int w = 0;
  int afterNSC = 1;
  for(   ; *str != '\0'; str++) {
    if(space_char(*str) && afterNSC) {
      afterNSC = 0;
      w++;
    }
    if(non_space_char(*str)) {
      afterNSC = 1;
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

/*Returns a freshly allocated zero-terminated string containing a copy of
  of the input string to place in history*/
char *copy_str_hist(char *str)
{
  str = word_start(str);
      int len = 0;
      while(*str != '\0') { // determines string length
	len++;
	str++;
      }
      char *strCopy = malloc(sizeof(char) * (len + 1));  //allocates memory for copy of string
      str = str - len;
      while(*str != '\0') {  //copy string to allocated memory
	*strCopy = *str;
	strCopy++;
	str++;
      }
      *strCopy = *str;
      strCopy = strCopy - len;
      return (char*) strCopy;
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
  *tokens = 0;
  tokens  = tokens - numWrds;
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  printf("\nTokens:");
  while(*tokens) {
    printf("\n%s", *tokens);
    tokens++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{
  char **temp = tokens;
  while(*temp != 0) {
    free(*temp);
    temp++;
  }
  free(*temp);
  free(tokens);
}
