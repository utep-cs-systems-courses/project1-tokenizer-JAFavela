#include <stdio.h>
#include "tokenizer.h"

//This file will have all the methods defined in tokenizer.h

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return c<'!';
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return c>='!';
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  for(   ; *str != '\0'; str++){
    if(space_char(*str) && non_space_char(*(str+1))){
      return (str+1);
    }
  }
  return str;
} 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
  for(   ; *word != '\0'; word++){
    if(space_char(*word)){
      return (word);
    }
  }
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  int w = 0;
  for(   ; *str != '\0'; str++){
    if(space_char(*str)){
      w++;
    }
  }
  return w+1;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  return 0;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  return 0;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  
}
