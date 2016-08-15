#include <iostream>
using namespace std;
bool islucky(int i){
    while(i){
        int j = i %10; i/=10;
        if(j != 4 and j != 7) return 0;
    }
    return 1;
}
int main(){
    for(int i = 4; i <= 7777; i++)
        if(islucky(i)) cout << i << endl;
    return 0;
}
