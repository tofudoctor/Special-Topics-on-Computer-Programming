#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LL long long

using namespace std;

const int N = 100;


struct TwoSAT{
    int n;
    vector<int> g[N * 2];
    bool mark[N * 2];
    stack<int> S;

    bool dfs(int x){
        if(mark[x ^ 1]) return false;
        if(mark[x]) return true;
        mark[x] = true;
        S.push(x);
        for(int i = 0; i < g[x].size(); i++){
            int v = g[x][i];
            if(!dfs(v)) return false;
        }
        return true;
    }

    void init(int _n){
        n = _n;
        for(int i = 0; i < 2 * n; i++) g[i].clear();
        memset(mark, 0, sizeof(mark));
    }

    void add(int x, int y){
        g[x].push_back(y);
    }

    bool solve(){
        for(int i = 0; i < 2 * n; i += 2){
            if(!mark[i] && !mark[i + 1]){
                while(!S.empty()) S.pop();
                if(!dfs(i)){
                    while(!S.empty()){
                        mark[S.top()] = false;
                        S.pop();
                    }
                    if(!dfs(i + 1)) return false;
                }
            }
        }
        return true;
    }
};
TwoSAT T_sat;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int S, A, m, a1, s1, a2, s2;
        cin >> S >> A >> m;
        T_sat.init(S + A);
        for(int i = 1; i <= m; i++){
            cin >> s1 >> a1 >> s2 >> a2;
            s1--, a1--, s2--, a2--;
            a1 *= 2; s1 = 2 * A + 2 * s1; a2 *= 2; s2 = 2 * (A + s2);
            if(s1 == s2 && a1 == a2) continue;
            if(a2 < a1){
                s1 = s1 ^ 1;
                s2 = s2 ^ 1;
            }
            if(s2 < s1){
                a1 ^= 1;
                a2 ^= 1;
            }
            if(a1 == a2){
                T_sat.add(a1 ^ 1, a2);
                continue;
            }
            if(s1 == s2){
                T_sat.add(s1 ^ 1, s2);
                continue;
            }
            T_sat.add(a1 ^ 1, s1);
            T_sat.add(s1 ^ 1, a1);
            T_sat.add(a2 ^ 1, s2);
            T_sat.add(s2 ^ 1, a2);
            T_sat.add(a1 ^ 1, a2);
            T_sat.add(s1 ^ 1, s2);
            T_sat.add(a2 ^ 1, a1);
            T_sat.add(s2 ^ 1, s1);
        }

        if(T_sat.solve()) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}