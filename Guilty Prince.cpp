/*
    author    : MishkatIT
    created   : Wednesday 2023-12-13-21.43.50
*/

#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';

using namespace std;
using ll        = long long;
using ld        = long double;
const ll mod    = 1e9 + 7;
const ll N      = 25;
const ll inf    = 1e9;
const ll linf   = 1e18;

bool vis[N][N];
char arr[N][N];
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dfs(int x, int y)
{
    vis[x][y] = true;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >=0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && arr[nx][ny] != '#') {
            cnt += dfs(nx, ny);

        }
    }
    return cnt;
}

int main()
{
    fio;
    int t;
    cin >> t;
    int cs = 0;
    while (t--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                vis[i][j] = false;
            }
        }

        cin >> m >> n;
        int sx, sy;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
            }
        }
//        debug(sx)debug(sy)
        cout << "Case " << ++cs << ": " << dfs(sx, sy) << '\n';
    }
    return 0;
}


