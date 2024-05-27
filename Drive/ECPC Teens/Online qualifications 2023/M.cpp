#include <bits/stdc++.h>
using namespace std;
#define int long long
#define A first
#define B second



signed main(){
  int n , m;
  cin >> n >> m;

int v[(int)n+1] , d[(int)n+1];
  for (int i = 1 ; i<=n ; i++) cin >> v[i];
  for (int i = 1;  i<=n ; i++) cin >> d[i];

  int l = 0 , r = 1e9 , md, s;
  while(l<=r){
    s = 0;
    md = (l+r)/2;
    for (int i = 1 ; i<=n ; i++) {if (v[i] >= md) s+=(v[i]-md)/d[i] + 1;}
    if (s < m) r = md-1;
    else l = md+1;
  }
  l--;
  l = max(0ll , l); s = 0 ; int ans = 0;
  for (int i = 1 ; i<=n ; i++) {
    if (v[i] >= l){
       s+=(v[i]-l)/d[i] + 1;
       int t = (v[i]-l)/d[i] + 1;
      ans+= (t * v[i]) - (t*(t-1)/2)*d[i];
    }
     }
     ans-=(l * max(0ll , s-m));
  cout << ans;
}
