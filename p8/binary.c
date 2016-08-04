//Authors: Janak Jobanputra and Janesh Gupta

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * replace_first_x(char y, char num[]);
void display(char *num);

int main()
{
  printf("Binary number: ");
  char *num;
  num = (char*) malloc(79*sizeof(char));
  scanf("%s",num);
  char *num2;
  num2=(char*)malloc(79*sizeof(char));
  display(num);
  printf("%s\n%s\n", num, num2); 
  return 0;
}

void display(char *num)
{
  int i;
  for(i=0; i<79;i++)
    if(num[i] == 'x')
      break;
  if(i==79)
    printf("%s\n", num);
  else
  {
    char num1[79];
    char num2[79];
    strcpy(num1, num);
    strcpy(num2, num);
    strcpy(num1, replace_first_x('0', num1));
    strcpy(num2, replace_first_x('1', num2));
    display(num1);
    display(num2);	
  }
}

char * replace_first_x(char y, char num[])
{
  int x;
  for(x=0;x<79;x++)
  {
    if(num[x]=='x')
      break;	
  }
  num[x]= y;
  return num;
}
