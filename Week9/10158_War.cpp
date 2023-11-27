/*
    並查集經典問題，紀錄每個點到根節點的距離
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int p[N], d[N], n;

int find(int x){
    if(p[x] != x){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) p[i] = i;

    int c, a, b;
    while(cin >> c >> a >> b && (c || a || b)){
        int pa = find(a), pb = find(b);
        if(c == 1){
            if(pa == pb && (d[a] - d[b]) % 2 != 0) cout << "-1\n";
            else if(pa != pb){
                p[pa] = pb;
                d[pa] = d[b] - d[a];
            }
        }
        else if(c == 2){
            if(pa == pb && (d[a] - d[b] + 1) % 2 != 0) cout << "-1\n";
            else if(pa != pb){
                p[pa] = pb;
                d[pa] = d[b] - d[a] + 1;
            }
        }
        else if(c == 3){
            if(pa == pb && (d[a] - d[b]) % 2 == 0) cout << "1\n";
            else cout << "0\n";
        }
        else if(c == 4){
            if(pa == pb && (d[a] - d[b] + 1) % 2 == 0) cout << "1\n";
            else cout << "0\n";
        }
    }

    return 0;
}