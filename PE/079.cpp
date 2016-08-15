//保留

#include <iostream>
#include <fstream>

#define ll long long int

using namespace std;


int main(){
    
    ll ans = 0;
    
    ifstream ifs;
    
    int log[50][3] = {0};
    
    char ch;
    
    ifs.open("keylog.txt");
    if(!ifs){
        exit(-1);
    }
    int i = 0;
    while( ( ch = ifs.get() ) != EOF){
        if( ch == '¥n'){
            i++;
            int j = 0;
        }else {
            log[i][j] = ch - '0';
            j++;
        }
    }
    
    ifs.close();

    cnt[10][3] = {0};
    for( int a = 0; a < 50; a++){
        for( int b = 0; b < 3; b++){
            cnt[log[a][b]][b]++;
        }
    }
    
    bool fflag[10] = true;
    for( int a = 0; a < 10; a++){
        if( cnt[a][0] > 0 && cnt[a][1] == 0 && cnt[a][2] == 0){
            ans *= 10;
            ans += a;
        }
    }

    return 0;
}
/*
手計算でできるねこれ
ソース書くより圧倒的に速く出せるね
*/