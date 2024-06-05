#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<long long> tree;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int left, int right) {
        if (left == right) {
            tree[node] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build(arr, 2 * node, left, mid);
            build(arr, 2 * node + 1, mid + 1, right);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    long long query(int node, int left, int right, int ql, int qr) {
        if (ql > right || qr < left) {
            return LLONG_MAX;
        }
        if (ql <= left && right <= qr) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        long long leftmin = query(2 * node, left, mid, ql, qr);
        long long rightmin = query(2 * node + 1, mid + 1, right, ql, qr);
        return min(leftmin, rightmin);
    }
};

int main() {
    int t;
    cin >> t;
    int cs = 0;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        SegmentTree st(arr);
        cout << "Case " << ++cs << ":\n";
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << st.query(1, 0, n - 1, l - 1, r - 1) << '\n'; // Adjust indices to be zero-based
        }
    }
    return 0;
}
