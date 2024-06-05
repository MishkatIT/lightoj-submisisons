/*
    Author    : MishkatIT
    Created   : Tuesday 04-06-2024 17:58:34
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for (int cs = 1; cs <= tc; cs++) {
        int n;
        cin >> n;
        vector<vector<ll>> v(2 * n + 5, vector<ll>(n + 5));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = n + 1; i < 2 * n; i++) {
            int j = i - n + 1;
            int cnt = n - (i - n);
            while (cnt--) {
                cin >> v[i][j];
                j++;
            }
        }
        vector<vector<ll>> dp(2 * n + 5, vector<ll> (n +5));
        for (int i = 1; i < 2 * n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]) + v[i][j];
            }
        }
        // debug(v);
        // debug(dp);
        ll ans = 0;
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dp[2 * n - 1][j]);
        }   

        cout << "Case " << cs << ": ";
        cout << ans << '\n';
    }
    return 0;
}