/*
 * Dijkstra's Algorithm (Single-Source Shortest Path)
 * Time: O(E log V)
 * Use: Finding shortest paths from a single source node
 */
struct Dijkstra {
    int n;
    vector<vector<pair<int, int>>> adj;
    vector<int> dist;
    vector<int> parent; 

    Dijkstra(int N) {
        n = N;
        adj.resize(n + 1);
        dist.assign(n + 1, inf);
        parent.assign(n + 1, -1);
    }

    void add_edge(int u, int v, int wt, bool undirected = true) {
        adj[u].push_back({v, wt});
        if (undirected) adj[v].push_back({u, wt});
    }

    void solve(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            if (d > dist[node]) continue;
            
            for (auto &[nbr, wt] : adj[node]) {
                if (dist[nbr] > dist[node] + wt) {
                    dist[nbr] = dist[node] + wt;
                    parent[nbr] = node;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
    }

    vector<int> get_path(int target) {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) path.push_back(v);
        reverse(all(path));
        return path;
    }
};
