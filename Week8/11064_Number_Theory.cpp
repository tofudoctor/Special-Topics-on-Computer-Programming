/*

求 1~n 中不互質且 % n = 0 的數的個數 = n - 互質的數的個數 - % n = 0 的個數 + 1 (兩者交集為一)

*/

#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n){
        int euler = n, fact = 1, t = n;

        for(int i = 2; i <= t / i; i++){
            if(t % i == 0){
                int s = 0;
                while(t % i == 0){
                    t /= i;
                    s++;
                }
                euler = euler - euler / i;
                fact *= s + 1;
                
            }
        }
        if(t > 1){
            euler = euler - euler / t;
            fact *= 2;
        }

        cout << n - euler - fact + 1 << "\n";
    }

    return 0;
}