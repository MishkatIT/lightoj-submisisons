#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
void basicIO() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
       int n;
        cin >> n;
        n++;
        for (int i = 1; i <= n; i++) {
            long long cur;
            for (int j = 0; j < i; j++) {
                if (j == 0) {
                    cur = 1;
                } else {
                    cur *= (i - j);
                    cur /= j;
                }
                cout << cur << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
