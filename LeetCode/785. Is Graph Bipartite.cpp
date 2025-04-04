class Solution {
public:
    bool DFS(vector<vector<int>>& adj,vector<int>&color, int u , int currColor)
    {
        color[u] = currColor;

        for(int &v : adj[u])
        {
            if(color[v] == color[u])
                return false;
            if(color[v] == -1 && DFS(adj,color,v,1-currColor) == false)
                return false;
            
        }
        return true;
    }
    bool BFS(vector<vector<int>>& adj,vector<int>&color, int u , int currColor)
    {
        queue<int>que;
        que.push(u);
        color[u] = currColor;

        while(!que.empty())
        {
            int front = que.front();
            que.pop();

            for(int &v: adj[front])
            {
                if(color[v] == color[front])
                    return false;
                
                if(color[v] == -1)
                {
                    color[v] = 1-color[front];
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>color(n,-1);
        //DFS Approach
        // for(int i = 0 ; i < n ;i++)
        // {
        //     if(color[i] == -1 && DFS(graph,color,i,1) == false) // 1 -> Red , 0 -> Green assumption
        //         return false;
        // }

        //BFS Approach
        for(int i = 0 ; i<n;i++)
        {
            if(color[i] == -1 && BFS(graph,color,i,1) == false)
                return false;
        }

        return true;
    }
};

Time Complexity (TC)
DFS/BFS TC: O(V + E)

Each node and edge is visited exactly once.

V = number of vertices, E = number of edges.

Space Complexity (SC)
DFS SC: O(V) (recursion stack + color array)

BFS SC: O(V) (queue + color array)

Why BFS is More Optimized?
1.No recursion overhead (avoids stack overflow for very large graphs).

2.Level-wise processing makes it easier to track color changes.

3.Better cache locality (queue-based traversal is faster in practice).

Further Optimizations (If Needed)
Early Termination: If any component is not bipartite, return immediately.

Union-Find (Disjoint Set Union - DSU): Can be used for dynamic bipartite checks, but BFS/DFS is simpler for this problem.