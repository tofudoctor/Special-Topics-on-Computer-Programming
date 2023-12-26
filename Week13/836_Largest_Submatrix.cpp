#include<bits/stdc++.h>

using namespace std;

const int N = 30;
int t, a[N][N], S[N][N];

int query(int i1, int j1, int i2, int j2){
    return S[i2][j2] - S[i1 - 1][j2] - S[i2][j1 - 1] + S[i1 - 1][j1 - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        memset(a, 0, sizeof a);
        memset(S, 0, sizeof S);
        string s;
        int n = 1, res = 0;

        cin >> s;
        n = s.size();
        for (int j = 1; j <= n; j++) a[1][j] = s[j - 1]-'0';
        for (int i = 2; i <= n; i++){
            cin >> s;
            for (int j = 1; j <= n; j++)
                a[i][j] = s[j - 1]-'0';
        }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                for(int k = 1; k <= i; k++)
                    for(int l = 1; l <= j; l++){
                        int tmp = query(k, l, i, j);
                        if(tmp == (i - k + 1)*(j - l + 1))
                            res = max(res, tmp);
                    }

        cout << res << "\n";
        if(t) cout << "\n";
    }

    return 0;
}