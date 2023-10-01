/*

先把長度拿去因數分解，用因數和 Rabin-Karp 去找是不是合法字串，小心輸出噁心人

*/
#include <bits/stdc++.h>

#define ULL unsigned long long

using namespace std;

const int N = 1e6 + 10;
ULL h[N], p[N];
string tmp;

ULL find(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    p[0] = 1;
    while(getline(cin, tmp) && tmp != "."){
        if(tmp == ""){
            if(t++) cout << "\n";
            cout << 0;
            continue;
        }
        memset(h, 0, sizeof h);
        vector<int> factor;
        string s = '#' + tmp;
        int n = s.size() - 1, cnt = 0, ans = 1;
        for(int i = 1; i <= n; i++){
            h[i] = h[i - 1] * 131 + s[i];
            p[i] = p[i - 1] * 131;
        }

        for(int i = 1; i <= n / i; i++){
            if(n % i == 0){
                factor.push_back(i);
                if(i != n / i) factor.push_back(n / i);
            }
        }

        for(auto f : factor){
            cnt = 0;
            for(int i = 1; i + f - 1 <= n;){
                if(find(i, i + f - 1) == find(1, f)){
                    cnt++;
                    i += f;
                }
                else{
                    cnt = 0;
                    break;
                }   
            }
            ans = max(ans, cnt);
        }

        cout << ans << "\n";
    }

    return 0;
}