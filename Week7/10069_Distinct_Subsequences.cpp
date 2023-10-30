#include<bits/stdc++.h>

using namespace std;

const int base = 1e9;
string T, S;
int tt;

vector<int> add(vector<int> &A, vector<int> &B){
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size() || i < B.size(); i++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % base);
        t /= base;
    }
    if(t) C.push_back(t);

    return C;
}

void show(vector<int> &A){
    cout << A.back();
    for(int i = A.size() - 2; i >= 0; i--){
        int tmp = A[i], cnt = 0;
        while(tmp){
            tmp /= 10;
            cnt++;
        }
        for(int j = 0; j < 9 - cnt; j++) cout << 0;
        cout << A[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tt;
    while(tt--){
        cin >> S;
        cin >> T;
        int n = S.size(), m = T.size();
        vector<int> dp[m + 1];

        dp[0].push_back(1);

        for(int i = 1; i <= n; i++)
            for(int j = m; j >= 1; j--)
                if(S[i - 1] == T[j - 1]) dp[j] = add(dp[j], dp[j - 1]);

        show(dp[m]);
        cout << "\n";
    }

    return 0;
}