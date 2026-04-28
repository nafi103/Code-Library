/*
 * Prim's Algorithm (Minimum Spanning Tree)
 * Time: O(E log V)
 * Use: Finding the MST and its total cost
 */
class Edge {
public:
    int u, v, wt;
};

struct CompareEdge {
    bool operator()(Edge a, Edge b) {
        return a.wt > b.wt;
    }
};

struct PrimsMST {
    int n;
    vector<vector<pair<int, int>>> adj;

    PrimsMST(int N) {
        n = N;
        adj.resize(n + 1);
    }

    void add_edge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    pair<vector<pair<int, int>>, int> solve(int start = 1) {
        vector<pair<int, int>> mst;
        int total_cost = 0;
        priority_queue<Edge, vector<Edge>, CompareEdge> pq;
        vector<bool> visited(n + 1, false);

        for (auto x : adj[start]) {
            pq.push({start, x.first, x.second});
        }
        visited[start] = true;

        while (!pq.empty()) {
            Edge edge = pq.top();
            pq.pop();
            
            if (visited[edge.v]) continue;
            
            visited[edge.v] = true;
            mst.push_back({edge.u, edge.v});
            total_cost += edge.wt;
            
            for (auto x : adj[edge.v]) {
                if (!visited[x.first]) {
                    pq.push({edge.v, x.first, x.second});
                }
            }
        }
        return {mst, total_cost};
    }
};
