#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
void basicIO() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}

int main() {
    // basicIO();
    // Your cpp code here
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        n++;
        for (int i = 1; i <= n; i++) {
            long long cur = 1;
            cout << cur << ' ';
            for (int j = 1; j < i; j++) {
                cur *= (i - j);
                cur /= j;
                cout << cur << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
