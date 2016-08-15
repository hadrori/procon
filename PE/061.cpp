#include <iostream>
#include <cstdlib>

using namespace std;

void hoge( int nums[][10000], int l, bool* pflag, int sum, int cnt);

int f = 0;

int main(){
    
    int nums[10][10000] = {0};
    
    
    //4桁角数生成
    for( int i = 3; i < 9; i++){
        int n = 1;
        int cnt = 0;
        while(1){
            int tmp = 0;
            switch( i){
                case 3:
                    tmp = n * ( n + 1) / 2;
                    break;
                case 4:
                    tmp = n * n;
                    break;
                case 5:
                    tmp = n * ( 3 * n - 1) / 2;
                    break;
                case 6:
                    tmp = n * ( 2 * n - 1);
                    break;
                case 7:
                    tmp = n * ( 5 * n - 3) / 2;
                    break;
                case 8:
                    tmp = n * ( 3 * n - 2);
                    break;
            }
            
            if( tmp > 1000 && tmp < 10000){
                nums[i][cnt++] = tmp;
            }
            n++;
            if( tmp > 10000){
                break;
            }
        }
    }
    
    int c = 0;
    bool pflag[10] = {false};
    while( nums[8][c] > 0){
        int l = nums[8][c] % 100;
        f = nums[8][c] / 100;
        int sum = nums[8][c];
        pflag[8] = true;
        
        hoge( nums, l, pflag, sum, 1);
        c++;
    }
    
    return 0;
}

void hoge( int nums[][10000], int l, bool* pflag, int sum, int cnt){
    
    if( cnt == 6){
        if( l == f){
            cout << sum << endl;
            exit(1);
        }else {
            return;
        }
    }
    
    int c = 0;
    for( int i = 3; i < 8; i++){
        if( !pflag[i]){
            pflag[i] = true;
            int c = 0;
            while( nums[i][c] > 0){
                if( l == nums[i][c] / 100){
                    hoge( nums, nums[i][c] % 100, pflag, sum + nums[i][c], cnt + 1);
                }
                c++;
            }
            pflag[i] = false;
        }
    }

    return;
}

/*
P3,n=n(n+1)/2
P4,n=n2
P5,n=n(3n-1)/2
P6,n=n(2n-1)
P7,n=n(5n-3)/2
P8,n=n(3n-2)
*/