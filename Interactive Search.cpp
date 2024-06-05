#include <bits/stdc++.h>
using namespace std;

int main() {
    int low = 1, high = 1e9;
    int n;
    cin >> n;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        cout << "guess " << mid << endl;
        string resp;
        cin >> resp;
        if (resp == "low") {
            low = mid + 1;
        } else if (resp == "high") {
            high = mid - 1;
        } else {
            return 0;
        }
    }    
    return 0;
}
