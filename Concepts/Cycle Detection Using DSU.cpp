
/**
 * Cycle Detection Using DSU.cpp
 * Implementation of cycle detection in an undirected graph using Disjoint Set Union (DSU).
 *
 * This code uses the DSU (Union-Find) algorithm to detect cycles in an undirected graph.
 * It maintains two arrays: `parent` and `rank` to efficiently manage the connected components.
 * 
 * Functions:
 * - `find(int x)`: Finds the representative (root) of the set containing `x` using path compression.
 * - `Union(int x, int y)`: Merges two sets containing `x` and `y` based on rank.
 * - `detectCycle(int n, vector<int> adj[])`: Detects if there is a cycle in the graph represented by adjacency list `adj`.
 * 
 * Time Complexity:
 * - `find` and `Union` operations: O(α(n)), where α(n) is the inverse Ackermann function (very small, nearly constant).
 * - Overall complexity of `detectCycle`: O(E * α(n)), where E is the number of edges and n is the number of nodes.
 */
vector<int>parent;
vector<int>rank;

int find(int x)
{
    if(x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
    int parent_x = find(x);
    int parent_y = find(y);

    if(parent_x != parent_y)
    {
        if(rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] <  rank[parent_y])
        {
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
}

int detectCycle(int n, vector<int>adj[])
{
    parent.resize(n);
    rank.resize(n);
    
    for(int i =0;i <n ;i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }
    for(int u = 0 ; u < n ;u++)
    {
        for(int &v : adj[u]) // process every node  if they are in same set so there will be a cycle if we are processing it again.
        {
            if(u < v)  
            {
                int set1 = find(u);
                int set2 = find(v);
                
                if(set1 == set2 )
                return 1;
                
                Union(u,v);
            }
        }
    }
    return 0;
}
