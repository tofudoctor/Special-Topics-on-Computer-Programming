#include<bits/stdc++.h>

using namespace std;

const int N = 30;
int t, a[N][N], l[N], r[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        memset(a, 0, sizeof a);
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
                if(a[i][j] == 1) 
                    a[i][j] += a[i - 1][j];
            

        for(int i = 1; i <= n; i++){
            stack<int> s;
            for(int j = 1; j <= n; j++){
                while(!s.empty() && a[i][s.top()] >= a[i][j]) s.pop();
                if(s.empty()) l[j] = 0;
                else l[j] = s.top();
                s.push(j);
            }

            while(!s.empty()) s.pop();

            for(int j = n; j >= 0; j--){
                while(!s.empty() && a[i][s.top()] >= a[i][j]) s.pop();
                if(s.empty()) r[j] = n + 1;
                else r[j] = s.top();
                s.push(j);
            }

            for(int k = 1; k <= n; k++) res = max(res, (r[k] - l[k] - 1) * a[i][k]);
        }        

        cout << res << "\n";
        if(t) cout << "\n";
    }

    return 0;
}