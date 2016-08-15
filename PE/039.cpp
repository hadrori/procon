#include <iostream> 

typedef long long ll;

using namespace std;

ll Euclid( ll m, ll n){
    if( m % n == 0){
        return n;
    }
    m %= n;
    if( m > n){
        return Euclid( m, n);
    }else{
        return Euclid( n, m);
    }
}

bool coprime( ll m, ll n){
    ll t = Euclid(m,n);
    if(t == 1) return true;
    else return false;
}

int main(){
    
    int p[1500] = {0};
    
    for(int l = 1; l < 501; l++){
        for(int m = 2; l * m < 1001; m++){
            for(int n = 1;  n < m; n++){
                if( coprime(m,n) && ((m - n) % 2 == 1) && (2*l*m*(m+n) < 1001)) p[2*l*m*(m+n)]++;
            }
        }
    }
    int max = 0;
    int t = 0;
    for(int i = 0; i < 1001; i++){
        if(max < p[i]){
            max = p[i];
            t = i;
        }
    }
    
    cout << t << endl;
    return 0;
}