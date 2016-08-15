#include <iostream>

typedef long long ll;

using namespace std;

bool pandigital(ll n){
    bool mflag[10] = {false};
    mflag[0] = true;
    while(n > 0){
        int t = n % 10;
        if(mflag[t]) return false;
        mflag[t] = true;
        n /= 10;
    }
    
    for(int i = 1; i < 10; i++){
        if(!mflag[i]) return false;
    }
    return true;
}

int pow(int n, int k){
    int m = 1;
    for(int i = 0; i < k; i++){
        m *= n;
    }
    
    return m;
}

int dig(int n){
    int t = 0;
    while( n > 0){
        n /= 10;
        t++;
    }
    return t;
}

int main(){
    
    for(int n = 2; n < 10; n++){
        
        int d = pow(10,9 / n);
        for(int k = d - 1; k > d / 10; k--){
            int t = 0;
            for(int i = 1; i <= n; i++){
                t *= pow(10,dig(k*i));
                t += k * i;
            }
            if(pandigital(t)){
                cout << t << endl;
                return 0;
            }
           //  cout << 'A' << endl;
        }
       
    }
    cout << 'B' << endl;
    return 0;
}