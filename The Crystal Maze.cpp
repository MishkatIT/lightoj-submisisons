/*
    author    : MishkatIT
    created   : Saturday 2023-08-12-00.08.01
*/
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
using ll        = long long;
using ld        = long double;
const ll mod    = 1e9 + 7;
const ll N      = 510;
const ll inf    = 1e9;
const ll linf   = 1e18;
int n, m;
int mem[510][510];
const int dx []= {1, -1, 0, 0};
const int dy []= {0, 0, 1, -1};
void bfs(int r, int c, char arr[][N])
{
    queue<pair<int, int>> q, temp;
    q.push({r, c});
    int tot = (arr[r][c] == 'C');
    mem[r][c] = 1;
    while(!q.empty()) {
        int f = q.front().first;
        int s = q.front().second;
        for (int i = 0; i < 4; i++) {
            int x = f + dx[i];
            int y = s + dy[i];
            char nxt = arr[x][y];
            if(nxt != '#' && x >= 1 && x <= n && y >= 1 && y <= m && !mem[x][y]) {
                q.push({x, y});
                tot += (nxt == 'C');
                mem[x][y] = 1;
            }
        }
        temp.push({f, s});
        q.pop();
    }
    while(!temp.empty()) {
        mem[temp.front().first][temp.front().second] = tot;
        temp.pop();
    }
}


int main()
{
    fio;
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mem[i][j] = 0;
            }
        }
        int q;
        cin >> n >> m >> q;
        char arr[N][N];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
            }
        }
        cout << "Case " << cs << ": " << '\n';
        while(q--) {
            int r, c;
            cin >> r >> c;
            if(mem[r][c]) {
                cout << mem[r][c] << '\n';
                continue;
            }
            bfs(r, c, arr);
            cout << mem[r][c] << '\n';
        }
    }
    return 0;
}

