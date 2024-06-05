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
    while (t--) {
        double a, b, c;
        cin >> a >> b >> c;
        double s = (a + b + c) / 2;
        double x = (s  - a) * (s - b) * (s - c);
        cout << "Area = " << fixed << setprecision(3) << sqrtl(s * x) << '\n';
    }
    return 0;
}
