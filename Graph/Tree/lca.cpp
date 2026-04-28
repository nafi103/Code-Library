/*
 * Lowest Common Ancestor (Binary Lifting)
 * Time: O(N log N) build, O(log N) query
 * Use: Finding LCA, kth ancestor, tree distance
 */
vector<vector<int>> t, parents;
vector<int> level; 
int mx;

void dfs(int node, int parent, int cLevel){
    level[node] = cLevel;
    parents[0][node] = parent;
    for(auto &x: t[node]){
        if(x!=parent) dfs(x,node, cLevel+1);
    }
}

// Call this from your actual main() after reading the tree edges
void build_lca(int root, int n) {
    mx = log2(n) + 2;
    parents.assign(mx, vector<int>(n + 1, -1));
    level.assign(n + 1, 0);
    
    dfs(root, -1, 0);
    
    for(int i = 1; i < mx; i++){
        for(int j = 1; j <= n; j++){
            int prevParent = parents[i-1][j];
            if(prevParent != -1) {
                parents[i][j] = parents[i-1][prevParent];
            }
        }
    }
}

int kthParent(int a, int k){
    for(int i = 0; i<mx; i++){
        if(a==-1) return a;
        if(k&(1<<i)) a = parents[i][a];
    }
    return a;
}

int lca(int a, int b){
    if(level[a]>level[b]){
        a = kthParent(a, level[a] - level[b]);
    }else{
        b = kthParent(b, level[b] - level[a]);
    }
    if(a==b) return a;
    for(int i = mx-1; i>=0; i--){
        if(parents[i][a]!=parents[i][b]){
            a = parents[i][a];
            b = parents[i][b];
        }
    }
    return parents[0][a];
}

int distance(int a,int b){
    return level[a]+level[b] - 2*level[lca(a,b)];
}
