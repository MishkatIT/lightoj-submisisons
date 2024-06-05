/*
    author    : MishkatIT
    created   : Saturday 2023-08-12-16.38.51
*/
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
using ll        = long long;
using ld        = long double;
const ll mod    = 1e9 + 7;
const ll N      = 1005;
const ll inf    = 1e9;
const ll linf   = 1e18;
vector<int> factors[N];
int dfs (int u, int v) {
  vector<int> vis(N, -1);
  queue<int> q;
  q.push(u);
  vis[u] = 0;
  while(!q.empty()) {
    for (auto& i : factors[q.front()]) {
      int nxt = q.front() + i;
      if(nxt <= v && vis[nxt] == -1) {
        q.push(nxt);
        vis[nxt] = vis[q.front()] + 1;
        if(nxt == v) {
          return vis[nxt];
        }
      }
    }
    q.pop();
  }
  return vis[v];
}
void precal()
{
    for (int i = 1; i < N; i++) {
        int temp = i;
        for (int j = 2; j < i; j++) {
            if(temp % j == 0) {
                factors[i].push_back(j);
                while(temp % j == 0) {
                    temp /= j;
                }
            }
        }
    }
}

int main()
{
    fio;
    precal();
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int u, v;
        cin >> u >> v;
        cout << "Case " << cs << ": " << dfs(u, v) << '\n';
    }
    return 0;
}

