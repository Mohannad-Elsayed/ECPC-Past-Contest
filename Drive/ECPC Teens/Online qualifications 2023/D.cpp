#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[a[i]] == i);
    }
    ans /= 2;
    cout << ans;
}
