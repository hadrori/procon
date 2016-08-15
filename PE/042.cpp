#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    
    ifstream ifs;
    
    char words[5000][20] = {0};
    
    char ch;
    int maxi = 1;
    int maxj = 0;
    
    ifs.open("words.txt");
    if(!ifs){
        exit(-1);
    }
    int i = 0;
    int j = 0;
    while( ( ch = ifs.get() ) != EOF){
        if( ch == ','){
            i++;
            maxi++;
            j = 0;
        }else if( ch != '"'){
            words[i][j] = ch;
            j++;
            if( maxj < j){
                maxj = j;
            }
        }
    }
    
    ifs.close();
    
    int cnt = 0;
    
    int t[100] = {0};
    for( int n = 1; n < 100; n++){
        t[n] = n * ( n + 1) / 2;
    }

    for( int i = 0; i < maxi; i++){
        j = 0;
        int sum = 0;
        while( words[i][j] > 0){
            sum += words[i][j] - 'A' + 1;
            j++;
        }
        j = 1;
        while( sum >= t[j]){
            if( sum == t[j]){
                cnt++;
                break;
            }
            j++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}
