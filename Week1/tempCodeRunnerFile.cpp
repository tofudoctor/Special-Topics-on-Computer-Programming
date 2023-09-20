#include<bits/stdc++.h>

#define PII pair<int, int>
using namespace std;

const int N = 30;

int t, p[N], u;
char c;

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void Union(int a, int b){
    if(find(a) == find(b)) return;

    p[find(a)] = find(b);
    u--;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> c;
        string s;
        u = c - 'A' + 1;
        for(int i = 0;i < N;i++) p[i] = i;

        cin.ignore();

        while(getline(cin, s) && s != ""){
            int a = find(s[0] - 'A'), b = find(s[1] - 'A');
            Union(a, b);
        }

        cout << u << "\n\n";
    }

    return 0;
}