#include <iostream>
#include <cmath>

using namespace std;

int prime[100];
int primeCount[100];
bool nums[28123] = {0};
int abundant[10000] = {0};


int main(){
  
  prime[0] = 2;
  int max = 0;
  for( int i = 3; i < sqrt(28124); i++){
    bool pflag = true;
    for( int j = 0; prime[j] <= sqrt(i); j++){
      if( i % prime[j] == 0){
	pflag = false;
	break;
      }
    }
    if(pflag){
      prime[++max] = i;
    }
  }
  
  abundant[0] = 12;

  int max2 = 0;
  for(int i = 13; i < 28124; i++){
    int sum = 0;

    for( int j = 1; j <= i / 2; j++){
      if( i % j == 0){
	sum += j;
	  
	if( sum > i){
	  abundant[++max2] = i;
	  break;
	}
	  
      }
	
    }
  }

  for(int i = 0; i <= max2; i++){
    for( int j = i; j <= max2; j++){
      if( abundant[i] + abundant[j] < 28124){
	nums[abundant[i] + abundant[j]] = 1;
      }
    }
  }
  long int sum = 0;
  for( int i = 0; i < 28124; i++){
    if(nums[i] == 0){
      sum += i;
    }
  }

  cout << sum << endl;
  return 0;
}
