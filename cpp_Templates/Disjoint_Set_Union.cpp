// DSU or Union-Find using Union by size and path compression

class DSU {
    vector<int> parent, size;
    
    DSU (int n) {
        for (int i=0;i<=n;i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    public:
    // path compression
    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
    
    // Union by size
    void unify(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        
        if (pu == pv) return;
        
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
    void print() {
        for (int i=0;i<parent.size();i++) {
            cout << i << " " << parent[i] << " " << size[i] << "\n";
        }
    }
};

// DSU dsu(n);
// dsu.findPar(i);
// dsu.unify(i,j);


// only path compression takes O(logN) time, but with size compression it takes O(4*alpha) which is almost constant time.
