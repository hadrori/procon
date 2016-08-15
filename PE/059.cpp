#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
    
    ifstream ifs;
    
    int codes[10000] = {0};
    
    char ch;
    int ac[100] = {0};
    int bc[100] = {0};
    int cc[100] = {0};
    int maxa = 0, maxb = 0, maxc = 0;
    int numa = 0, numb = 0, numc = 0;
    
    ifs.open("cipher1.txt");
    
    if(!ifs){
        exit(-1);
    }
    
    long int i = 0;
    while( ( ch = ifs.get() ) != EOF){
        if( ch == ','){
            int tm = ( i + 1) % 3;
            if( tm == 1){
                ac[codes[i]]++;
                if(ac[codes[i]] > maxa){
                    maxa = ac[codes[i]];
                    numa = codes[i];
                }
            }else if( tm == 2){
                bc[codes[i]]++;
                if(bc[codes[i]] > maxb){
                    maxb = bc[codes[i]];
                    numb = codes[i];
                }
            }else{
                cc[codes[i]]++;
                if(cc[codes[i]] > maxc){
                    maxc = cc[codes[i]];
                    numc = codes[i];
                }
            }
            i++;
        }else if( ch >= '0' && ch <= '9'){
            codes[i] *= 10;
            codes[i] += ch - '0';
            cout << codes[i] << endl;
        }
    }
    cout << endl;
    int tm = ( i + 1) % 3;
    if( tm == 1){
        ac[codes[i]]++;
        if(ac[codes[i]] > maxa){
            maxa = ac[codes[i]];
            numa = codes[i];
        }
    }else if( tm == 2){
        bc[codes[i]]++;
        if(bc[codes[i]] > maxb){
            maxb = bc[codes[i]];
            numb = codes[i];
        }
    }else{
        cc[codes[i]]++;
        if(cc[codes[i]] > maxc){
            maxc = cc[codes[i]];
            numc = codes[i];
        }
    }
    
    ifs.close();
    
    int keya = numa ^ (int)' ';
    int keyb = numb ^ (int)' ';
    int keyc = numc ^ (int)' ';

    int sum = 0;
    char words[10000] = {0};
    for( int k = 0; k <= i; k++){
        int t = ( k + 1) % 3;
        if( t == 1){
            words[k] = codes[k] ^ keya;
        }else if( t == 2){
            words[k] = codes[k] ^ keyb;
        }else{
            words[k] = codes[k] ^ keyc;
        }
        sum += (int)words[k];
        cout << words[k];
        //cout << (int)words[k];
    }
    cout << endl;
    //cout << (int)'?' << endl;
    cout << sum << endl;


    return 0;
}