/*
假設a[i] = 第i個事件所需工作天, c[i] = 第i個事件所需罰金/天, s[i] = 第i個事件前面經過幾天

若 1. 先A[i] 再 A[i + 1] => s[i] * c[i] + (s[i] + a[i]) * c[i + 1]     = s[i] * c[i] + s[i] * c[i + 1] + a[i] * c[i + 1]
   2. 先A[i + 1] 再 A[i] => s[i] * c[i + 1] + (s[i] + a[i + 1]) * c[i] = s[i] * c[i] + s[i] * c[i + 1] + a[i + 1] * c[i]

    也就是說, 當a[i] * c[i + 1] < a[i + 1] * c[i] 代表1.比較好, 反之2.好

    最後是uva慣例, 輸入輸出噁心環節, 搞定之後結束了
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 1010;
int t, n;
pair<pair<int, int>, int> A[N]; // a, c, idx

bool cmp(pair<pair<int, int>, int> lhs, pair<pair<int, int>, int> rhs){
    if(lhs.first.first * rhs.first.second < rhs.first.first * lhs.first.second) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1, a, c; i <= n; i++){
            cin >> a >> c;
            A[i - 1] = {{a, c}, i};
        }

        sort(A, A + n, cmp);

        for(int i = 0; i < n;i ++){
            if(i == n - 1) cout << A[i].second << "\n";
            else cout << A[i].second << " ";
        } 

        if(t) cout << "\n";
    }
}