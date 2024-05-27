#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
       int n, c;
       cin >> n >> c;
       int a[n];
       for (int i = 0; i < n; i++) {
           cin >> a[i];
       }
       sort(a, a+n);
       int l = 0, r = n-1, ans = 0;
       while (l < r) {
           ans++;
           if (a[l] + a[r] + 1 <= c) {
               l++, r--;
           } else {
               r--;
           }
       }
       cout << ans + (l == r) << "\n";
   }
}

