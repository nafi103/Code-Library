/**
 * Trie (Prefix Tree) - Vector Based
 * * Efficiency: O(Length of string) for all operations.
 * Space: O(Σ * Total Characters), where Σ is alphabet size (26).
 * Features: 
 * - pass: Number of strings having this prefix.
 * - end : Number of strings ending at this node (handles duplicates).
 * - Memory efficient vector-based implementation (no pointers).
 */
struct Trie {
    struct Node {
        int next[26];
        int pass = 0;
        int end = 0;
        
        Node() { 
            memset(next, -1, sizeof(next)); 
        }
    };
    
    vector<Node> t;

    Trie() {
        t.assign(1, Node()); 
    }

    void insert(const string& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back();
            }
            v = t[v].next[c];
            t[v].pass++;
        }
        t[v].end++;
    }

    bool search(const string& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1 || t[t[v].next[c]].pass == 0) {
                return false; 
            }
            v = t[v].next[c];
        }
        return t[v].end > 0;
    }

    void erase(const string& s) {
        if (!search(s)) return; 
        
        int v = 0;
        for (char ch : s) {
            v = t[v].next[ch - 'a'];
            t[v].pass--;
        }
        t[v].end--;
    }
};