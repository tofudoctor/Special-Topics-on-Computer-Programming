#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

string s;
int q, l, r, cnt, a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> s){
        cout << "Case " << ++cnt << ":\n";
        cin >> q;

        int tmp = 0;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i + 1]) a[i] = tmp;
            else a[i] = tmp++;
        }
        int idx = s.size() - 1;
        if(s[idx] == s[idx - 1]) a[idx] = tmp;
        else a[idx] = tmp++;

        while(q--){
            cin >> l >> r;
            if(a[l] == a[r]) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}