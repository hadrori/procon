#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdlib.h"

using namespace std;

int main(){

  ifstream ifs;

  string name[10000];

  char ch;

  ifs.open("names.txt");
  if(!ifs){
    exit(-1);
  }
  int i = 0;
  while( ( ch = ifs.get() ) != EOF){
    if( ch == ','){
      i++;
    }else if( ch != '"'){
      name[i].append(1,ch);
    }
  }

  ifs.close();

  sort( &name[0], &name[i+1]);

  long int scoreSum = 0;
  for( int k = 0; k <= i; k++){
    int temp = 0;
    for( int j = 0; j < name[k].size(); j++){
      temp += name[k][j] - 'A' + 1;
    }
    scoreSum += temp * ( k + 1 ) ;
  }

  cout << scoreSum << endl;
  return 0;
}
