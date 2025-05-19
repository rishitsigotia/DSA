class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(n == 1) // Edge Case
            return true;

        unordered_map<int,vector<int>>adj; // As we list of edges, convert it to adjacency list.
        vector<int>visited(n+1,-1);
        for(auto it : dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 1; i <= n; ++i) // check for the disconnected components
        {
            if (visited[i] == -1) 
            {
                queue<int> que;
                que.push(i);
                visited[i] = 1;

                while (!que.empty()) 
                {
                    int curr = que.front();
                    que.pop();

                    for (int neighbor : adj[curr]) 
                    {
                        if (visited[neighbor] == -1) 
                        {
                            visited[neighbor] = 1 - visited[curr];
                            que.push(neighbor);
                        } else if (visited[neighbor] == visited[curr]) 
                        {
                            return false;
                        }
                    }
                }
            }
    }

    return true;
    }
};

// This is a classic problem of Bipartitiion of Graph , Graph Coloring etc.