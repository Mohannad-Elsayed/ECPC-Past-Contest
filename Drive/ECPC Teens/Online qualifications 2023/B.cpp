#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, inf = 1e17 + 5, mod = 1e9 + 7;
int main()
{
   ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
   string x, y = "SCPCTeensQual2024";
   cin >> x;
   int cnt = 0;
   for (int i = 0; i < 17; i++)
      cnt += (x[i] != y[i]);
   cout << cnt;
}
