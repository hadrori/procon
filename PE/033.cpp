#include <iostream>
#include <cmath>

#define ll long long int

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


int main(){
    
    int count = 4;
    
    int am = 1;
    int ac = 1;
    for( int m = 12; m < 100; m++){
        for( int c = 11; c < m; c++){
            if( m % 10 == 0 ){
                break;
            }
            if( c % 10 != 0){
                int k = Euclid( m, c);
                int fm = m / k;
                int fc = c / k;
                int m1 = m / 10;
                int m2 = m % 10;
                int c1 = c / 10;
                int c2 = c % 10;
                if( m1 == c1){
                    int l = Euclid( m2, c2);
                    if( m2 / l == fm && c2 / l == fc){
                        am *= fm;
                        ac *= fc;
                        count--;
                        cout << c << '/' << m << endl;
                    }
                }
                if( m1 == c2){
                    int l = Euclid( m2, c1);
                    if( m2 / l == fm && c1 / l == fc){
                        am *= fm;
                        ac *= fc;
                        count--;
                        cout << c << '/' << m << endl;
                    }
                }
                if( m2 == c1){
                    int l = Euclid( m1, c2);
                    if( m1 / l == fm && c2 / l == fc){
                        am *= fm;
                        ac *= fc;
                        count--;
                        cout << c << '/' << m << endl;
                    }
                }
                if( m2 == c2){
                    int l = Euclid( m1, c1);
                    if( m1 / l == fm && c1 / l == fc){
                        am *= fm;
                        ac *= fc;
                        count--;
                        cout << c << '/' << m << endl;
                    }
                }
                if( count == 0){
                    break;
                }
            }
        }
        if( count == 0){
            break;
        }
    }
    int a = Euclid( am, ac);
    am /= a;
    ac /= a;
    cout << am << endl;
    return 0;
}










