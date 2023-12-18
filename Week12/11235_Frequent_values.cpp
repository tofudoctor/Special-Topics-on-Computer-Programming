#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
int n, q, ql, qr, a[N], lv[N << 2], rv[N << 2], mv[N << 2], ar, am;
 
void build(int x, int l, int r){
    if (l == r){
        lv[x] = 1;
        rv[x] = 1;
        mv[x] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    if (mv[x << 1] == mid - l + 1 && a[l] == a[mid + 1]) lv[x] = lv[x << 1] + lv[x << 1 | 1];
    else lv[x] = lv[x<<1];
    if (mv[x << 1 | 1] == r - mid && a[r] == a[mid]) rv[x] = rv[x << 1 | 1] + rv[x << 1];
    else rv[x] = rv[x << 1 | 1];
    mv[x] = max(mv[x], mv[x << 1]);
    mv[x] = max(mv[x], mv[x << 1 | 1]);
    if (a[mid] == a[mid + 1]) mv[x] = max(mv[x], rv[x << 1]+lv[x << 1 | 1]);
    return;
}
 
void query(int ql, int qr, int x, int l, int r){
    if (ql <= l && r <= qr){
        am = max(am, mv[x]);
        if (a[l] == a[l - 1]){
            am = max(am, ar + lv[x]);
        }
        if (rv[x] == r - l + 1 && a[l] == a[l - 1]) ar += rv[x];
        else ar = rv[x];
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) query(ql, qr, x << 1, l, mid);
    if (mid < qr) query(ql, qr, x << 1 | 1, mid + 1, r);
    return;
}
 
int main() {
    while (cin >> n){
        if (n == 0) break;
        for (int i = 1; i <= n * 4; i++){
            lv[i] = 0;
            rv[i] = 0;
            mv[i] = 0;
        }
        cin >> q;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        build(1, 1, n);
        for (int i = 0; i < q; i++){
            cin >> ql >> qr;
            ar = 0;
            am = 0;
            query(ql, qr, 1, 1, n);
            cout << am << "\n";
        }
    }
    return 0;
}