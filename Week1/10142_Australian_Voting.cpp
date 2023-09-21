/*
閱讀測驗 模擬
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 30;
int t, n, res[N];
string name[N];
bool st[N];
vector<int> votes[1010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    cin.ignore();

    while(t--){
        memset(st, 0, sizeof st);
        for(int i = 0; i < 1010; i++) votes[i].clear();
        cin >> n;
        for(int i = 1; i <= n; i++){
            if(getline(cin, name[i]) && name[i] == ""){
                i--;
            }
        }

        string vote;
        int cnt = 0;
        while(getline(cin, vote) && vote != ""){
            stringstream ss;
            ss << vote;
            int tmp;
            while(ss >> tmp) votes[cnt].push_back(tmp);
            cnt++;
        }

        while(true){
            memset(res, 0, sizeof res);
            for(int i = 0; i < cnt; i++){ // 找每個votes的最佳候選人
                for(int j = 0; j < n; j++){
                    if(!st[votes[i][j]]){
                        res[votes[i][j]]++;
                        break;
                    }
                }
            }

            int mmax = 0, mmin = 2000;
            for(int i = 1; i <= n; i++) { // 挑出可用的max/min
                if(!st[i]){
                    mmax = max(mmax, res[i]); 
                    mmin = min(mmin, res[i]);
                }     
            }

            if(mmax > (cnt + 1 >> 1) || mmax == mmin){
                for(int i = 1; i <= n; i++){
                    if(res[i] == mmax){
                        cout << name[i] << "\n";
                    }
                }
                break;
            }
            else{
                for(int i = 1; i <= n; i++){
                    if(res[i] == mmin)
                        st[i] = true;
                }
            }
        }
            
        if(t) cout << "\n";

    }
}