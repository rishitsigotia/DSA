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
                else if(rank[parent_x] < rank[parent_y])
                    parent[parent_x] = parent_y;
                else
                {
                    parent[parent_x] = parent_y;
                    rank[parent_y]++;
                }
            }
        }
        void DFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited, int u , long long &size)
        {
            visited[u] = true;
            size++;
    
            for(int &v:adj[u])
            {
                if(!visited[v])
                {
                    DFS(adj,visited,v,size);
                }
            }
    
        }
        long long countPairs(int n, vector<vector<int>>& edges) {
            // First Doing it with DFS  approach
            // long long ans = 0;
            // unordered_map<int,vector<int>>adj;
            // vector<bool>visited(n,false);
            // int currentSize = n;
    
            // for(auto &vec:edges)
            // {
            //     int u = vec[0];
            //     int v = vec[1];
                
            //     adj[u].push_back(v);
            //     adj[v].push_back(u);
            // }
    
            // for(int i = 0 ; i<n ;i++)
            // {
            //     if(!visited[i])
            //     {
            //         long long size = 0;
            //         DFS(adj,visited,i,size);
    
            //         ans += size *(currentSize-size);
            //         currentSize -= size;
            //     }
            // }
            // return ans;
    
            // DSU Approach
    
            long long ans = 0;
            long long currentSize = n;
            rank.resize(n,0);
            parent.resize(n);
            for(int i = 0 ; i<n;i++)
            {
                parent[i] = i;
            }
    
            for(auto &vec : edges)
            {
                int u = vec[0];
                int v = vec[1];
    
                Union(u,v);
            }
    
            unordered_map<int,int>mp;
            for(int i = 0 ; i < n ;i++)
            {
                int parent = find(i); // it will give direct leader so we can count basis of leader.
                mp[parent]++;
            }
            for(auto &it : mp)
            {
                ans += (it.second)*(currentSize-it.second);
                currentSize -= it.second;
            }
            return ans;
        }
    };