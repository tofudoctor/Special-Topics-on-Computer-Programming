/*

快樂水題!判斷因數個數偶數還奇數即可

*/

#include<bits/stdc++.h>

using namespace std;

unsigned int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n && n){
        unsigned int tmp = sqrt(n);
        if(tmp * tmp == n) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}