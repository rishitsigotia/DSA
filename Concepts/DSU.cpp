void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
    int rootA = find(a, parent);
    int rootB = find(b, parent);
    
    if (rootA != rootB) {
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int find(int a, vector<int>& parent) {
    if (parent[a] != a) {
        parent[a] = find(parent[a], parent); // Path compression
    }
    return parent[a];
}




// Explanation of the above code:
// The `Union` function merges two sets represented by `a` and `b`.
// It uses the `find` function to determine the root of each set.
// The `rank` vector is used to keep the tree flat by attaching the smaller tree under the larger tree.
// The `find` function implements path compression to optimize future queries.