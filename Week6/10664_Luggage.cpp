#include<bits/stdc++.h>

using namespace std;


const int N = 210;
int t, w[N], dp[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    cin.ignore();
    string s;
    while(t-- && getline(cin, s)){
        memset(w, 0, sizeof w);
        memset(dp, 0, sizeof dp);
        stringstream ss;
        ss << s;
        int tmp, cnt = 0, sum = 0;
        while(ss >> tmp){
            w[++cnt] = tmp;
            sum += tmp;
        }

        if(sum / 2 * 2 != sum){
            cout << "NO\n";
            continue;
        }

        for(int i = 1; i <= cnt; i++)
            for(int j = sum / 2; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + w[i]);

        if(dp[sum / 2] == sum / 2) cout << "YES\n";
        else cout << "NO\n";    
    }
    
    return 0;
}