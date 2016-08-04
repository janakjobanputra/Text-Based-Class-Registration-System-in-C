//Authors: Janak Jobanputra and Janesh Gupta
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int find_path(int row, int col, char arr[8][8]);

int main(int argc, char *argv[]){
  FILE *inp;
  inp =fopen(argv[1], "r");
  char array[8][8];
  int x, y;
  int row=7;
  int col=7;
  for(x=0;x<8;x++)
    {
    for(y=0;y<8;y++)
      fscanf(inp, "%c", &array[x][y]);
        fgetc(inp);
	}	
	if(find_path(row,col,array)==0)
      find_path(row,col,array);
	return 0;
}

int find_path(int row,int col, char arr[8][8]){


  if(row<0 || col<0)
    return 0;
  if(arr[row][col] == 'X')
    return 0;
  if(row==0 && col==1)
   {	printf("(0,1)\n");
		return 1;
}
  if(row>7 || col>7)
    return 0;
  arr[row][col]= 'X';
  if (find_path(row-1, col, arr)
    ||find_path(row, col-1, arr)
    || find_path(row+1, col, arr)
    || find_path(row, col+1, arr))
   {
     printf("(%d, %d)\n", row, col);
     return 1;
   }
  return 0;
}

