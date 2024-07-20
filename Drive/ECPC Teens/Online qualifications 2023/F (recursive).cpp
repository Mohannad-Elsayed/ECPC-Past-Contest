#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
bool a[N][N];
int dp[N][N][N];

int rec(int l, int r, int i){
    if (l == r)return 1;
    if (~dp[l][r][i])return dp[l][r][i];
    
    bool cl = false, cr = true;
    if (l == i)cl = true;
    if (r == i)cr = true;
    for(int j = l; j < i; j++) {
        if (a[i][j] && rec(l, i-1, j)) {
            cl = true;
        }
    }
    for(int j = i+1; j <= r; j++) {
        if (a[i][j] && rec(i+1, r, j)) {
            cr = true;
        }
    }
    return dp[l][r][i] = (cl & cr);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '1');
        }
    }
    memset(dp, -1, sizeof dp);
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if (rec(1, n, i)) {
            ans++;
        }
    }
    cout << ans;
}
