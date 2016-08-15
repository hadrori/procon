#include <iostream>
#include <cmath>

#define ll long long int

using namespace std;

ll sum = 0;
bool ans[10000] = {false};

bool judge( bool* aflag, bool* bflag, int prd);


int main(){
    
    int prd;
    
    for( int i = 1; i < 10; i++){
        bool aflag[10] = {false};
        aflag[0] = true;
        aflag[i] = true;
        for( int j = 1234; j < 9877; j++){
            int tmp = j;
            bool bflag[10] = {false};
            bflag[0] = true;
            bool dflag = true;
            while( tmp > 0){
                int t = tmp % 10;
                if( aflag[t] || bflag[t]){
                    dflag = false;
                    break;
                }
                bflag[t] = true;
                tmp /= 10;
            }
            if( dflag){
                prd = i * j;
                if( prd < 10000 && prd > 1000){
                    if( judge( aflag, bflag, prd)){
                        if( !ans[prd]){
                            cout << i << ' ' << j << ' ' << prd << endl;
                            sum += prd;
                            ans[prd] = true;
                        }
                    }
                }
            }
        }
    }
    
    for( int i = 12; i < 99; i++){
        bool aflag[10] = {false};
        aflag[0] = true;
        int tmp = i;
        aflag[tmp%10] = true;
        tmp /= 10;
        if(!aflag[tmp%10]){
            aflag[tmp%10] = true;
            for( int j = 123; j < 988; j++){
                bool bflag[10] = {false};
                bflag[0] = true;
                tmp = j;
                int t = tmp / 10;
                int u = t / 10;
                if( !aflag[tmp%10] && !aflag[t%10] && !aflag[u%10]){
                    bflag[tmp%10] = true;
                    tmp /= 10;
                    if( !bflag[tmp%10]){
                        bflag[tmp%10] = true;
                        tmp /= 10;
                        if( !bflag[tmp%10]){
                            bflag[tmp%10] = true;
                            
                            prd = i * j;
                            
                            if( prd < 10000 && prd > 999){
                                if( judge( aflag, bflag, prd)){
                                    if( !ans[prd]){
                                        cout << i << ' ' << j << ' ' << prd << endl;
                                        sum += prd;
                                        ans[prd] = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << sum << endl;

  return 0;

}

bool judge( bool* aflag, bool* bflag, int prd){
    
    int tmp = prd;
    bool cflag[10] = {false};
    while( tmp > 0){
        int t = tmp % 10;
        if( aflag[t] || bflag[t] || cflag[t]){
            return false;
        }
        cflag[t] = true;
        tmp /= 10;
    }
    
    return true;
    
}













