#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

#define N 100000000
#define M 1000000009

#define MAX 1000000

bool primes[MAX+1];

void prime(){
    
    for(int i=0 ; i<=MAX ; i++){
        primes[i] = (i<=1)? false : true ;
    }
    
    for(int i=2 ; i<=sqrt(MAX)+1 ; i++){
        if(primes[i]){
            for(int j=i*2 ; j<=MAX ; j+=i){
                primes[j] = false;
            }
        }
    }
    
    return;
}

int main(){


}
