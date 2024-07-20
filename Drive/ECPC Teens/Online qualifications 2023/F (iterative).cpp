#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];
bool arr[101][101];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1 ; j <= n; j++){
            char c;
            cin >> c;
            if (c == '1') {
                arr[i][j] = true;
            }
        }
    }
    for (int sz = 0; sz < n; sz++){
        for (int l = 1; l <= n - sz; l++){
            int r = l+sz;
            for (int p = l; p <= r; p++){
                int x = 0 , y = 0;
                if (p == l) x = 1;
                if (p == r) y = 1;
                for (int i = l; i < p; i++) {
                    if (arr[p][i] && dp[l][p-1][i]) x = 1;
                }
                for (int i = p+1; i <= r; i++){
                    if (arr[p][i] && dp[p+1][r][i]) y = 1;
                }
                if (x && y) dp[l][r][p] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (dp[1][n][i]) cnt++;
    }
    cout << cnt;
}

