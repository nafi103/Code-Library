/*
 * Fenwick Tree (2D)
 * 0-indexed implementation.
 * constructor(arr): O(N * M) linear time construction.
 * query(x, y): Returns the sum of elements in rectangle from (0, 0) to (x, y).
 * sum(x1, y1, x2, y2): Returns the sum in rectangle from (x1, y1) to (x2, y2).
 * add(x, y, delta): Adds delta to the cell at (x, y).
 */

template <typename T>
struct Fenwick_Tree2D {
    vector<vector<T>> bit;
    int n, m;

    Fenwick_Tree2D(int _n, int _m){
        n = _n;
        m = _m;
        bit.assign(n, vector<T>(m, 0));
    }

    Fenwick_Tree2D(const vector<vector<T>> &a) : Fenwick_Tree2D(sz(a), sz(a) > 0 ? sz(a[0]) : 0){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bit[i][j] += a[i][j];
                int r_col = j | (j + 1);
                if (r_col < m)
                    bit[i][r_col] += bit[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int r_row = i | (i + 1);
                if (r_row < n)
                    bit[r_row][j] += bit[i][j];
            }
        }
    }

    T query(int x, int y) const {
        T ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    T sum(int x1, int y1, int x2, int y2) const {
        T ret = 0;
        ret += query(x2, y2);
        ret -= query(x1 - 1, y2);
        ret -= query(x2, y1 - 1);
        ret += query(x1 - 1, y1 - 1);
        return ret;
    }

    void add(int x, int y, T delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};