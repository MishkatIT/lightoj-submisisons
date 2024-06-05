#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int XC, YC, r, X, Y;
        cin >> XC >> YC >> r >> X >> Y;

        // বৃত্তের কেন্দ্র হতে স্থানাঙ্ক (X, Y) পর্যন্ত দূরত্ব
        long long distance = sqrt(pow(X - XC, 2) + pow(Y - YC, 2));

        // দূরত্ব বৃত্তের ব্যাসার্ধের চেয়ে ছোট হলে বিন্দুটি বৃত্তের অভ্যন্তরে অবস্থিত
        if (distance < r) {
            cout << "The point is inside the circle" << endl;
        } else {
            cout << "The point is not inside the circle" << endl;
        }
    }

    return 0;
}
