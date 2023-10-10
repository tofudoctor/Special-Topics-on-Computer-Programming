/*

假設給 n 則可得出     1 =   kn  +  r
             =>     11 = 10kn + 10r + 1 其中 10r + 1 可被拆成商 (10r + 1) / n 和餘 (10r + 1) % n
             =>    111 = 商 + 餘
             => 11..11 = 商 + 0
             因此目標就是把餘數變成零要花幾次

PS:難得這次沒被換行坑到

*/
#include<bits/stdc++.h>

#define LL long long

using namespace std;

LL n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n){
        LL cnt = 1, r = 1 % n;
        while(r){
            r = (10 * r + 1) % n;
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}