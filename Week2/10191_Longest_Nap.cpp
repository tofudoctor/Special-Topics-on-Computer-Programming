#include <bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

int n, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n){
        vector<PII> segs;
        cout << "Day #" << ++t << ": the longest nap starts at ";
        string s1, s2, s3;

        for(int i = 0; i < n; i++){
            cin >> s1 >> s2;
            getline(cin, s3);

            int h1 = (s1[0] - '0') * 10 + (s1[1] - '0'), m1 = (s1[3] - '0') * 10 + (s1[4] - '0'), h2 = (s2[0] - '0') * 10 + (s2[1] - '0'), m2 = (s2[3] - '0') * 10 + (s2[4] - '0');
            segs.push_back({h1 * 60 + m1, h2 * 60 + m2});
        }
        segs.push_back({1080, 1080});

        sort(segs.begin(), segs.end());

        int st = 600, ed = 600, ans = 0, napst = st;
        for(int i = 0; i <= n; i++){
            if(ed < segs[i].first){
                if(segs[i].first - ed > ans){
                    ans = segs[i].first - ed;
                    napst = ed;
                }
                st = segs[i].first;
                ed = segs[i].second;
            }
            else{
                if(ed >= segs[i].second) continue;
                else ed = segs[i].second;
            }
        }

        int m = napst % 60;
        cout << napst / 60 << ":";
        if(m < 10) cout << "0" << m;
        else cout << m; 
        cout << " and will last for ";
        if(ans >= 60) cout << ans / 60 << " hours and " << ans % 60 << " minutes.\n";
        else cout << ans << " minutes.\n";
    }

    return 0; 
}