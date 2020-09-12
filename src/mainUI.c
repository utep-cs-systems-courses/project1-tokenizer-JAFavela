#include <stdio.h>

//This will be the main ui file

int main()
{
  char str[50];
  printf("> ");
  scanf("%[^\n]",str);
  printf("%s\n",str);
  return 0;
}
