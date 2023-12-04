#include<bits/stdc++.h>

#define PII pair<int, int>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

bool st1[N], st2[N];
vector<PII> g[N], revg[N];
int n, m, s, d, dis[N], revdis[N];
set<pair<pair<int,int>,int>> se;

void dijkstra(int s)
{
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    memset(dis, 0x3f, sizeof dis);
    memset(st1, 0, sizeof st1);
    dis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        int x = pq.top().second;
        pq.pop();

        if(st1[x]) continue;

        st1[x] = true;
        for(auto it : g[x]){
            int u = it.first, w = it.second;
            if(dis[u] > dis[x] + w){
                dis[u] = dis[x] + w;
                pq.push({dis[u], u});
            }
        }
    }
}
void dijkstra2(int s)
{
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    memset(revdis, 0x3f, sizeof revdis);
    memset(st2, 0, sizeof st2);
    revdis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        int x = pq.top().second;
        pq.pop();

        if(st2[x]) continue;

        st2[x] = true;
        for(auto it : revg[x]){
            int u = it.first, w = it.second;
            if(revdis[u] > revdis[x] + w){
                revdis[u] = revdis[x] + w;
                pq.push({revdis[u], u});
            }
        }
    }
}
void dijkstra3(int s)
{
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    memset(dis, 0x3f, sizeof dis);
    memset(st1, 0, sizeof st1);
    dis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        int x = pq.top().second;
        pq.pop();

        if(st1[x]) continue;

        st1[x] = true;
        for(auto it : g[x]){
            int u = it.first, w = it.second;
            if(se.count({{x, u}, w})) continue;
            if(dis[u] > dis[x] + w){
                dis[u] = dis[x] + w;
                pq.push({dis[u], u});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n >> m && (n || m)){
        se.clear();
        for(int i = 0; i < N; i++){
            g[i].clear();
            revg[i].clear();
        } 

        cin >> s >> d;
        for(int i = 0, a, b, w; i < m; i++){
            cin >> a >> b >> w;
            g[a].push_back({b, w});
            revg[b].push_back({a, w});
        }

        dijkstra(s);
        dijkstra2(d);
        if(dis[d] == INF){
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < n; i++){
            for(auto it : g[i]){
                int u = it.first, w = it.second;
                if(dis[i] + revdis[u] + w == dis[d])
                    se.insert({{i, u}, w});
            }
        }

        dijkstra3(s);

        if(dis[d] == INF) cout << "-1\n";
        else cout << dis[d] << "\n";
    }
    return 0;
}