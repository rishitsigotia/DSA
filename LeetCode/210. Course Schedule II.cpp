class Solution {
private:
    void TPS(unordered_map<int,vector<int>>&adj,vector<int>&inDegree ,int n,vector<int>&ans)
    {
        queue<int>que;
        for(int i = 0;i<n;i++)
        {
            if(inDegree[i]==0)
                que.push(i);
        }
        while(!que.empty())
        {
            int front = que.front();
            ans.push_back(front);
            que.pop();

            for(int &v:adj[front])
            {
                inDegree[v]--;
                if(inDegree[v] == 0)
                    que.push(v);
            }
        }
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(n,0);
        vector<int>ans;
        for(auto &vec : prerequisites)
        {
            int v = vec[0];
            int u = vec[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        TPS(adj,inDegree,n,ans);

        if(ans.size() < n)
            return {};//vector<int>();
        return ans;
        
    }
};

Here we have to write the TP sort only first check the question first part then only proceed further.
1. Check and insert if there is cycle or not.
2. If cycle found the TP sort will not be possible so check if it is having less number of elements in ans.