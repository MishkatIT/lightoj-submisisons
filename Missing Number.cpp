#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int missing = 0;
        for (int i = 1; i <= n; i++) {
            missing ^= i;
        }
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            missing ^= x;
        }
        cout << missing << '\n';
    }
    return 0;
}
