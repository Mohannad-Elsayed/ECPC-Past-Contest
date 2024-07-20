#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define sz(s) int(s.size())
int n;
ll a[100], dp[100][59049], pw[10];

ll sol(int i, int mask) {
    if (i == n)return 0;
    ll &ret = dp[i][mask];
    if (~ret)return ret;
    ret = sol(i+1, mask);
    vector<int> cnt(10, 0), bit(10, 0);
    ll tmp = a[i];
    while (tmp) {
        cnt[(tmp % 10)]++;
        tmp /= 10;
    }
    int j = 0;
    while (mask) {
        bit[j++] = (mask % 3);
        mask /= 3;
    }
    bool f = true;
    for (int k = 0; k < 10; k++) {
        if (cnt[k] + bit[k] <= 2) {
            bit[k] += cnt[k];
        } else {
            f = false;
            break;
        }
    }
    if (f) {
        int msk = 0;
        for (int k = 0; k < 10; k++) {
            msk += (bit[k] * pw[k]);
        }
        ret = max(ret, a[i] + sol(i+1, msk));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pw[0] = 1;
    for (int i = 1; i < 10; i++) {
        pw[i] = (pw[i-1] * 3);
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < 59049; j++) {
                dp[i][j] = -1;
            }
        }
        cout << sol(0, 0) << "\n";
    }
}
