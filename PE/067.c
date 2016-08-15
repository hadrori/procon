#include "stdio.h"
#include "stdlib.h"

int main(void){

  int triangle[100][100];
  int i, j;

  FILE* fp;

  if((fp = fopen("triangle.txt", "r")) == NULL){
    exit(0);
  }
  char c;
  int flag = 0;
  i = 0;
  j = 0;
  while(1){

    if( j == 0){
      triangle[i][j] = 10 * ( fgetc(fp) - '0');
      triangle[i][j] += fgetc(fp) - '0';
      j++;
    }

    if( ( c = fgetc(fp)) == EOF){
      break;
    }
    if( c  == '\n'){
      i++;
      //printf("%da ", j);
      j = 0;
      triangle[i][j] = 10 * ( fgetc(fp) - '0');
      triangle[i][j] += fgetc(fp) - '0';
      //printf("%d %d\n", i, j);
      j++;
    }else if( c == ' '){
      //printf("a%c",c);
      triangle[i][j] = 10 * ( (c = fgetc(fp)) - '0');
      //printf("%c",c);
      triangle[i][j] += (c = fgetc(fp)) - '0';
      //printf("%c\n",c);
      j++;
    }
	
  }
  fclose(fp);

  int root[100][100];
  root[0][0] = triangle[0][0];
  root[1][0] = root[0][0] + triangle[1][0];
  root[1][1] = root[0][0] + triangle[1][1];

  for( i = 2; i < 100; i++){
      for( j = 0; j <= i; j++){
          if( j == 0){
              root[i][j] = root[i-1][j] + triangle[i][j];
          }else if( j == i){
              root[i][j] = root[i-1][j-1] + triangle[i][j];
          }else{
              if( root[i-1][j-1] > root[i-1][j]){
                  root[i][j] = root[i-1][j-1] + triangle[i][j];
              }else{
                  root[i][j] = root[i-1][j] + triangle[i][j];
              }
          }
      }
  }

  int max = 0;

  for( j = 0; j < 100; j++){
    if( root[99][j] > max){
      max = root[99][j];
    }
  }
  printf("%d\n", max);
  return 0;
}
