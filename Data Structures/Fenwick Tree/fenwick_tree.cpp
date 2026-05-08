template <typename T>
struct Fenwick_Tree{
    int n;
    vector<T> bit;

    Fenwick_Tree(int _n) : n(_n), bit(_n, 0) {}

    Fenwick_Tree(const vector<T> &arr){
        n = sz(arr);
        bit.assign(n, 0);
        for (int i = 0; i < n; i++){
            bit[i] += arr[i];
            int r = i | (i + 1);
            if(r < n)
                bit[r] += bit[i];
        }
    }

    T query(int r) const {
        T sum = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            sum += bit[r];
        return sum;
    }

    T query(int l, int r) const {
        if(l > r)
            return 0;
        return query(r) - query(l - 1);
    }

    void add(int idx, T delta){
        for(; idx < n; idx = idx | (idx + 1)){
            bit[idx] += delta;
        }
    }
};