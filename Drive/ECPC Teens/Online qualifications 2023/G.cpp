#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5, mod = 1e9 + 7;
ll subtree_size[N], depth[N];
vector<int> adj[N];
vector<pair<pair<int, int>, ll>> edges;

void dfs(ll u, ll p)
{
    subtree_size[u] = 1;
    ll ret = 1;
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
    }
    return;
}

int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.push_back({{x, y}, z});
    }
    dfs(1, 0);
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        int u = edges[i].first.first, v = edges[i].first.second;
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        ans += ((subtree_size[u] * (n - subtree_size[u])) % mod * edges[i].second) % mod;
        ans %= mod;
    }
    for (ll i = 2; i < n; i++) {
        ans = (ans * i) % mod;
    }
    cout << (ans * 2ll) % mod << "\n";
}

