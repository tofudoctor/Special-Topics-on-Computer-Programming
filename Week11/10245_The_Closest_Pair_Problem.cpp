/*
    最近點對，經典問題
*/

#include<bits/stdc++.h>

#define PDD pair<double, double>

using namespace std;

int n;
vector<PDD> p;

double dis(PDD a, PDD b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n && n){
        p.clear();
        double ans = 1e8;
        for (int i = 0; i < n; i++){
            double a, b;
            cin >> a >> b;
            p.push_back({a, b});
        }
        sort(p.begin(), p.end());
        set<PDD> s;
        s.insert({p[0].second, p[0].first});
        int l = 0;
        for (int i = 1; i < n; i++){
            double d = ans + 1;
            while(l < i && p[l].first < p[i].first - d){
                s.erase({p[l].second, p[l].first});
                l++;
            }
            auto it_l = s.lower_bound({p[i].second - d, 0});
            auto it_r = s.upper_bound({p[i].second + d, 0});
            for (auto it = it_l; it != it_r; it++)
                ans = min(ans, dis({it->second, it->first} , p[i]));
            
            s.insert({p[i].second, p[i].first});
        }

        if(ans < 10000) cout << fixed << setprecision(4) << ans << "\n";
        else cout << "INFINITY\n";
    }
    
    return 0;
}