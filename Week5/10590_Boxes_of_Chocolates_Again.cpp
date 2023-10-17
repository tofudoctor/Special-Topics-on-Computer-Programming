/*

大數(壓位)+完全背包

*/

#include<bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10, base = 1e9;
int n;
vector<int> dp[N];

vector<int> add(vector<int> &a, vector<int> &b){
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size() || i < b.size(); i++){
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % base);
        t /= base;
    }
    if(t) c.push_back(t);

    return c;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    dp[0].push_back(1);
    for(int i = 1; i < N; i++) dp[i].push_back(0);

    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j++)
            dp[j] = add(dp[j], dp[j - i]);
    
    while(cin >> n){
        cout << dp[n].back();
        for(int i = dp[n].size() - 2; i >= 0; i--){
            int tmp = dp[n][i], cnt = 0;
            if(tmp == 0) cnt++;
            while(tmp){
                tmp /= 10;
                cnt++;
            }
            for(int i = 0; i < 9 - cnt; i++) cout << 0;
            cout << dp[n][i];
        }
        cout << "\n";
    }
}