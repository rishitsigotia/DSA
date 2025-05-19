class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    int N;
    void DFS(vector<vector<int>>& graph , int u)
    {
        if(u == N-1) // if we reach the last node, push the entire path.
            result.push_back(path);
        
        for(auto &v : graph[u])
        {
            path.push_back(v);
            DFS(graph,v);
            path.pop_back(); // remove when backtracing 
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // 0 -> n-1 
        int n = graph.size();
        N = n;

        path.push_back(0); //starting from here.
        DFS(graph,0);

        return result;
        
    }
};

// This is normal DFS and backtracking logic to visit a end node starting with 0.
