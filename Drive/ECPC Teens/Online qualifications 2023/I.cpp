#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz(s) int(s.size())
#define F first
#define S second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char c[n][n];
    int dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            if (c[i][j] == '1') {
                dist[i][j] = 1;
            } else {
                dist[i][j] = 1e9;
            }
            if (j == i) {
                dist[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool f = true;
        for (int j = 0; j < n; j++) {
            f &= (dist[i][j] < 1e9);
        }
        ans += f;
    }
    cout << ans;
}
