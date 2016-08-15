#include <iostream>
#include <fstream>
#include <string>
#include "stdlib.h"

using namespace std;

int main(){

  ifstream ifs;

  char name[10000][20];

  char ch;

  ifs.open("names.txt");
  if(!ifs){
    exit(-1);
  }
  int i = 0;
  int j = 0;
  while( ( ch = ifs.get() ) != EOF){
    if( ch == ','){
      i++;
      j = 0;
    }else if( ch != '"'){
      name[i][j] = ch;
      j++;
    }
  }

  ifs.close();

  cout >> name[0] >> endl;

  return 0;
}
