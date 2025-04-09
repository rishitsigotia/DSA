class Solution {
    public:
        vector<int>parent;
        vector<int>rank;
    
        int find(int x)
        {
            if(x == parent[x])
                return x;
            
            return parent[x] = find(parent[x]);
        }
        void Union(int x , int y)
        {
            int parent_x = find(x);
            int parent_y = find(y);
    
            if(parent_x != parent_y)
            {
                if(rank[parent_x] > rank[parent_y])
                    parent[parent_y] = parent_x;
                else if (rank[parent_x] < rank[parent_y])
                    parent[parent_x] = parent_y;
                else{
                    parent[parent_x] = parent_y;
                    rank[parent_y]++;
                }
            }
        }
        void DFS(unordered_map<int,vector<int>>&adj , vector<bool>&visited,int u)
        {
            visited[u] = true;
    
            for(int &v: adj[u])
            {
                if(!visited[v])
                    DFS(adj,visited,v);
            }
        }
        int makeConnected(int n, vector<vector<int>>& connections) {
    
            int edges = connections.size();
            if(edges < n-1)
                return -1;
            // Union Find Approach
            // parent.resize(n);  
            // rank.resize(n,0);
    
            // for(int i = 0 ; i<n;i++)
            // {
            //     parent[i] = i;
            // }
    
            // for(auto vec : connections)
            // {
            //     int u = vec[0];
            //     int v = vec[1];
    
            //     int parent_u = find(u);
            //     int parent_v = find(v);
    
            //     if(parent_u == parent_v)
            //         continue;
                
            //     Union(u,v);
            //     n--;
            // }
            // return n-1;
    
            //DFS approach
            vector<bool>visited(n,false);
            unordered_map<int,vector<int>>adj;
            int component = 0;
            for(auto &vec: connections)
            {
                int u = vec[0];
                int v = vec[1];
    
                adj[u].push_back(v);
                adj[v].push_back(u); // Undirected Graph
            }
    
            for(int i = 0 ; i < n ; i++)
            {
                if(!visited[i])
                {
                    DFS(adj,visited,i);
                    component++;
                }
            }
            return component-1; // Jitte bhi component hoge minimum n-1 edge chahiye rhte connect krne.
    
        }
    };