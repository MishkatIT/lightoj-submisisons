#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    vector<int> lazy;
    string binary;
    int n;

    SegmentTree(string& str) {
        binary = str;
        n = binary.length();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = binary[left] - '0';
        } else {
            int mid = (left + right) / 2;
            build(2 * node, left, mid);
            build(2 * node + 1, mid + 1, right);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void propagate(int node, int left, int right) {
        if (lazy[node] % 2 != 0) {
            tree[node] = (right - left + 1) - tree[node];
            if (left != right) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int left, int right, int ql, int qr) {
        propagate(node, left, right);
        if (ql > right || qr < left) {
            return;
        }
        if (ql <= left && right <= qr) {
            tree[node] = (right - left + 1) - tree[node];
            if (left != right) {
                lazy[2 * node]++;
                lazy[2 * node + 1]++;
            }
            return;
        }
        int mid = (left + right) / 2;
        update(2 * node, left, mid, ql, qr);
        update(2 * node + 1, mid + 1, right, ql, qr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int left, int right, int ql, int qr) {
        propagate(node, left, right);
        if (ql > right || qr < left) {
            return 0;
        }
        if (ql <= left && right <= qr) {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_count = query(2 * node, left, mid, ql, qr);
        int right_count = query(2 * node + 1, mid + 1, right, ql, qr);
        return left_count + right_count;
    }

    void range_update(int ql, int qr) {
        update(1, 0, n - 1, ql, qr);
    }

    int range_query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        string binary;
        cin >> binary;
        int n = binary.length();

        int q;
        cin >> q;

        SegmentTree st(binary);

        cout << "Case " << tc << ":" << '\n';

        while (q--) {
            char op;
            cin >> op;

            if (op == 'I') {
                int i, j;
                cin >> i >> j;
                st.range_update(i - 1, j - 1); // Convert to 0-based index
            } else if (op == 'Q') {
                int i;
                cin >> i;
                int result = st.range_query(i - 1, i - 1); // Convert to 0-based index
                cout << result << '\n';
            }
        }
    }

    return 0;
}
