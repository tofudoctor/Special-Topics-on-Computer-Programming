/*

超級麻煩的題目，排序後找同一個名字& enter->exit再計算

*/
#include<bits/stdc++.h>

#define name first.first
#define time first.second 
#define st second.first
#define dis second.second

using namespace std;

int t, f[25];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        vector<pair<pair<string, string>, pair<int, int>>> rec; // name time st dis
        map<string, double> mp;
        for(int i = 0; i < 24; i++) cin >> f[i];
        cin.ignore();

        string s;
        while(getline(cin, s) && s != ""){
            stringstream ss;
            ss << s;
            string tmp[4];
            for(int i = 0; i < 4; i++) ss >> tmp[i];

            int dist = 0;
            for(int i = 0; i < tmp[3].size(); i++){
                dist *= 10;
                dist += tmp[3][i] - '0';
            }
            int status = 0;
            if(tmp[2][1] == 'n') status = 1;
            rec.push_back({{tmp[0], tmp[1]}, {status, dist}});
            mp[tmp[0]] = 2.0;
        }

        sort(rec.begin(), rec.end());
        rec.push_back({{"", ""}, {0, 0}});

        for(int i = 0; i < rec.size() - 1; i++){
            if(rec[i].name == rec[i + 1].name){
                if(rec[i].st && !rec[i + 1].st){
                    double d = abs((double)rec[i].dis - rec[i + 1].dis);
                    int hr = (rec[i].time[6] - '0') * 10 + rec[i].time[7] - '0';
                    mp[rec[i].name] += 1.00;
                    mp[rec[i].name] += (double)f[hr] * d / 100.00;
                }
            }
        }

        for(auto it : mp)
            if(it.second > 2.00)
                cout << fixed << setprecision(2) << it.first << " $" << it.second << "\n";

        if(t) cout << "\n";
    }
}