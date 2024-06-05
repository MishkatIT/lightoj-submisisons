/*
    author    : MishkatIT
    created   : Wednesday 2023-08-16-17.22.12
*/
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
using ll        = long long;
using ld        = long double;
const ll mod    = 1e9 + 7;
const ll N      = 110;
const ll inf    = 1e9;
const ll linf   = 1e18;

vector<int> adj[N];
map<pair<int, int>, int> cost;
vector<bool> vis(110);
int sum1, sum2;
int ini;

void func (int par)
{
    int cnt = 0;
    for (auto& i: adj[par]) {
        if(!vis[i]) {
            cnt = 0;
            vis[i] = true;
            sum1 += cost[ {par, i}];
            sum2 += cost[ {i, par}];
            func(i);
        } else {
            cnt++;
        }
        if(cnt == 2) {
            sum1 += cost[ {par, ini}];
            sum2 += cost[ {ini, par}];
            return;
        }
    }
}
int main()
{
    fio;
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {

        for (int i = 0; i < N; i++) {
            adj[i].clear();
        }
        cost.clear();
        vis.assign(vis.size(), false);
        sum1 = sum2 = 0;
        ini = -1;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            if(ini == -1) {
                ini = u;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[ {u, v}] = 0;
            cost[ {v, u}] = c;
        }

        vis[ini] = true;
        func(ini);
        cout << "Case " << cs << ": " << min(sum1, sum2) << '\n';
    }
    return 0;
}

