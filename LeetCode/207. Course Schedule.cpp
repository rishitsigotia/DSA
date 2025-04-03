class Solution {
public:
    // this solution is with BFS
    bool checkTPSort(unordered_map<int,vector<int>>&adj,vector<int>&inDegree ,int n )
    {
        queue<int>que;
        int count = 0;
        for(int i = 0 ; i<n;i++)
        {
            if(inDegree[i] == 0)
                que.push(i);
        }
        while(!que.empty())
        {
            int front = que.front();
            count++;
            que.pop();

            for(int &v : adj[front])
            {
                inDegree[v]--;
                if(inDegree[v] ==0)
                    que.push(v);
            }
        }
        if(count == n)
            return true;

        return false;
    }
    // this solution is with DFS
    bool checkCycleDFS(unordered_map<int,vector<int>>&adj,vector<bool>&inRec,vector<bool>&visited,int &u)
    {
        visited[u] = true;
        inRec[u] = true;

        for(int &v : adj[u])
        {
            if(!visited[v] && checkCycleDFS(adj,inRec,visited,v))
                return true;
            else if(inRec[v])
                return true;
        }
        inRec[u] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int>inDegree(n,0);
        unordered_map<int,vector<int>>adj;

        for(auto &vec : prerequisites)
        {
            int u = vec[1];  // 1,0 
            int v = vec[0];  // 1 complete krne ke liye 0 hona chahiye 0 --> 1

            adj[u].push_back(v);
            inDegree[v]++;
        }
        //we are using topological sort as the concept for that is u-->v  if we can write it that means there is no cycle
        //return checkTPSort(adj,inDegree,n);  //uncomment this for BFS solution.

        //this is by DFS
        vector<bool>visited(n,false);
        vector<bool>inRec(n,false);
        for(int i = 0; i < n ; i++)
        {
            if(!visited[i] && checkCycleDFS(adj,inRec,visited,i))
                return false;
        }
        return true;
    }
};


1. Time Complexity (TC)
The time complexity is determined by:

Visiting every node once (O(n))

Traversing every edge once (O(e), where e is the number of edges)

Breakdown:
Building the adjacency list (adj):

Iterating over prerequisites (which has e edges) → O(e)

DFS traversal (checkCycleDFS):

Each node is visited exactly once (O(n))

Each edge is traversed once (O(e))

Total DFS time → O(n + e)

Final TC:
Worst Case: O(n + e)

If the graph is dense (e ≈ n²), it becomes O(n²).

But typically, in course scheduling, e is proportional to n, so O(n + e) ≈ O(n) in practice.

2. Space Complexity (SC)
The space complexity is determined by:

Adjacency list (O(n + e))

Visited and recursion stack trackers (O(n))

Recursion call stack (O(n) in worst case)

Breakdown:
Adjacency List (adj):

Stores n nodes and e edges → O(n + e)

Visited & inRec arrays:

Two boolean arrays of size n → O(2n) ≈ O(n)

Recursion Stack (DFS depth):

In the worst case (a straight-line graph), recursion depth is n → O(n)

Final SC:
Total: O(n + e) (dominated by adjacency list)