#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

#define ll long long int

using namespace std;

bool fcheck( ll root[][80]);

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

    map< ll, ll> sumAd;
    
    for( i = 0; i < 80; i++){
        root[i][0] = matrix[i][0];
        sumAd.insert(make_pair( root[i][0], i * 100));
        //cout << root[i][0] << ' ' << sumAd[root[i][0]] << endl;
    }
    
    while( fcheck( root)){
        map<ll,ll>::iterator itr = sumAd.begin();
        ll min = itr->first;
        ll tmp = itr->second;
        i = tmp / 100;
        j = tmp % 100;
        for( int di = -1; di <= 1; di++){
            if( di == 0){
                if( j < 79 && root[i][j+1] == 0){
                    root[i][j+1] = min + matrix[i][j+1];
                    sumAd.insert(make_pair( root[i][j+1], i * 100 + j + 1));
                }
            }else {
                if( i+di <= 79 && i+di >= 0 && root[i+di][j] == 0){
                    root[i+di][j] = min + matrix[i+di][j];
                    sumAd.insert(make_pair( root[i+di][j], ( i + di) * 100 + j));
                }
            }
        }
        sumAd.erase(itr);
    }
    
    ll min = 10000000;
    for( int a = 0; a < 80; a++){
        if( min > root[a][79]){
            min = root[a][79];
        }
    }
    cout << min << endl;
    
    return 0;
}

bool fcheck( ll root[][80]){
    
    for( int i = 0; i < 80; i++){
        if( root[i][79] == 0){
            return true;
        }
    }
    
    return false;
}