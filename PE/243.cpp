#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

#define MAX 100000000

bool primes[MAX+1] = {false};

ll pr[MAX/2];


void prime(){
    
    int k = 0;
	for(int i=0 ; i<=MAX ; i++){
		primes[i] = (i<=1)? false : true ;
	}
    
	for(int i=2 ; i<=sqrt(MAX)+1 ; i++){
		if(primes[i]){
            pr[k++] = i;
            //cout << i << ' ';
			for(int j=i*2 ; j<=MAX ; j+=i){
				primes[j] = false;
			}
		}
        
	}
    
    return;
}
    

ll Euclid( ll m, ll n){
    if( m % n == 0) return n;
    
    m %= n;
    
    if( m > n) return Euclid( m, n);
    else return Euclid( n, m);
}

bool coprime( ll m, ll n){
    ll t = Euclid(m,n);
    if(t == 1) return true;
    else return false;
}

ll tR(ll d){
    vector<bool> copr(d);
    for(int i = 1; i < d; i++){
        copr[i] = false;
    }
    ll cnt = 1;
    for(int i = 2; i < d; i++){
        if(!copr[i] && !coprime(d,i)){
            for(int j = i; j < d; j += i){
                if(!copr[j]){
                    copr[j] = true;
                }
            }
        }else cnt++;
    }
    return cnt;
}


int main(){
   
    int d = 2;
    int i = 1;
    
    prime();

    int m = 2;
    int c = 1;
    while(1){

        if((c / m) < (15499 / 94744)){
            break;
        }
        m *= pr[i];
        c *= pr[i++]-1;
        int t = Euclid(m,c);
        m /= t;
        c /= t;
        
    }

    int k = 2;
    while(1){
        if( (c*k/m*k-1) < (15499 / 94744)){
            cout << k << endl;
            return 0;
        }
    }
    
    return 0;
}