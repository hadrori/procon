#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

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
    
    multimap< ll, ll> sumAd;
    sumAd.clear();
    ll root[80][80] = {0};
    
    root[0][0] = matrix[0][0];
    sumAd.insert(make_pair(root[0][0],0));

    
    while( root[79][79] == 0){
        multimap<ll,ll>::iterator itr = sumAd.begin();
        ll min = itr->first;
        ll tmp = itr->second;
        sumAd.erase(itr);
        i = tmp / 100;
        j = tmp % 100;
        int ni;
        int nj;
        
        for( int k = 0; k < 4; k++){
            switch(k){
                case 0: //up
                    ni = i - 1;
                    nj = j;
                    break;
                case 1: //down
                    ni = i + 1;
                    nj = j;
                    break;
                case 2: //right
                    ni = i;
                    nj = j + 1;
                    break;
                case 3: //left
                    ni = i;
                    nj = j - 1;
                    break;
            }
            
            if( ni >= 0 && ni < 80 && nj >= 0 && nj < 80){
                if( root[ni][nj] == 0){
                    root[ni][nj] = min + matrix[ni][nj];
                    sumAd.insert(make_pair(root[ni][nj],ni*100+nj));
                }
            }
            
        }
    }
    
    cout << root[79][79] << endl;
    return 0;
}