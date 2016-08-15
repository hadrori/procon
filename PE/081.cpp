#include <iostream>
#include <fstream>
#include <cstdlib>

#define ll long long int

using namespace std;


int main(){
    
    ifstream ifs;
    
    ll matrix[80][80] = {0};
    
    char ch;
    
    ifs.open("matrix.txt");
    if(!ifs){
        exit(-1);
    }
    int i = 0;
    int j = 0;
    while( ( ch = ifs.get() ) != EOF){
        if( ch == '\n'){
            i++;
            j = 0;
        }else if( ch == ','){
            j++;
        }else {
            matrix[i][j] *= 10;
            matrix[i][j] += ch - '0';
        }
    }
    
    ifs.close();
    
    ll root[80][80] = {0};
    
    root[0][0] = matrix[0][0];
    root[1][0] = root[0][0] + matrix[1][0];
    root[0][1] = root[0][0] + matrix[0][1];
    
    for( i = 2; i < 80; i++){//i段目(行列は斜めに見る)
        for( j = 0; j <= i; j++){//j列
            int k = i - j;//k行
            if( k == 0){
                root[k][j] = root[k][j-1] + matrix[k][j];
            }else if( k == i){
                root[k][j] = root[k-1][j] + matrix[k][j];
            }else {
                if( root[k][j-1] > root[k-1][j]){
                    root[k][j] = root[k-1][j] + matrix[k][j];
                }else{
                    root[k][j] = root[k][j-1] + matrix[k][j];
                }
            }
        }
    }
    for( i = 80; i < 159; i++){
        for( int k = 79; i - k <= 79; k--){
            j = i - k;
            if( root[k-1][j] > root[k][j-1]){
                root[k][j] = root[k][j-1] + matrix[k][j];
            }else{
                root[k][j] = root[k-1][j] + matrix[k][j];
            }
        }
    }
    
    cout << root[79][79] << endl;
    return 0;
}