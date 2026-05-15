/*
 * Standard Segment Tree (Point Update, Range Query)
 * Time: O(N) build, O(log N) update/query
 * Use: Range Sum, Range Min/Max, Range GCD
 */

struct Segment_Tree {

    struct Node {
        int value;
        Node(int val = 0) : value(val) {} 
        // Default values: sum -> 0, min -> inf, max -> -inf
    };

    Node merge(const Node &left, const Node &right) {
        return Node(left.value + right.value);
    }

    int n;
    vector<Node> st;

    Segment_Tree(const vector<int> &v, int _n) {
        n = _n;
        st.resize(4 * n + 1);
        build(1, 1, n, v);
    }

    void build(int node, int b, int e, const vector<int> &v) {
        if (b == e) {
            st[node] = Node(v[b]);
            return;
        }
        int mid = (b + e) / 2, left = 2 * node, right = 2 * node + 1;
        build(left, b, mid, v);
        build(right, mid + 1, e, v);
        st[node] = merge(st[left], st[right]);
    }

    void update(int node, int b, int e, int idx, const Node &value) {
        if (e < idx or b > idx) return;
        if (b == idx and e == idx) {
            st[node] = value;
            return;
        }
        int mid = (b + e) / 2, left = 2 * node, right = 2 * node + 1;
        update(left, b, mid, idx, value);
        update(right, mid + 1, e, idx, value);
        st[node] = merge(st[left], st[right]);
    }

    Node query(int node, int b, int e, int l, int r) {
        if (e < l or b > r) return Node();
        if (b >= l and e <= r) return st[node];
        int mid = (b + e) / 2, left = 2 * node, right = 2 * node + 1;
        Node query_left = query(left, b, mid, l, r);
        Node query_right = query(right, mid + 1, e, l, r);
        return merge(query_left, query_right);
    }

    int query(int l, int r){
        return query(1, 1, n, l, r).value;
    }

    void update(int idx, int value){
        Node tmp = Node(value);
        update(1, 1, n, idx, tmp);
    }
};
