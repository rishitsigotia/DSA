class Solution {
    public:
    //   This is used to fill stack , later it according to this DFS will be called.
      void DFSFillStack(vector<vector<int>> &adj,stack<int>&st,vector<bool>&visited,int u)
      {
          visited[u] = true;
          
          for(int &v : adj[u])
          {
              if(!visited[v])
              {
                  DFSFillStack(adj,st,visited,v);
              }
          }
          st.push(u);
          
      }
    
      /// @brief / This is used to call DFS and count answer from main function
      /// @param reverseAdj 
      /// @param visited 
      /// @param u 
      void DFS(vector<vector<int>>&reverseAdj,vector<bool>&visited,int u)
      {
          visited[u] = true;
          
          for(int v:reverseAdj[u])
          {
              if(!visited[v])
              {
                  DFS(reverseAdj,visited,v);
              }
          }
      } 
      int kosaraju(vector<vector<int>> &adj) {
          
          int n = adj.size();
          stack<int>st;
          vector<bool>visited(n,false);
          
          //Step 1. Fill the stack , use for loop to cover disconnected component also.
          for(int u = 0 ; u < n ;u++)
          {
              if(!visited[u])
                  DFSFillStack(adj,st,visited , u);
          }
          
          //Step 2. Reverse the graph to count SCC
          vector<vector<int>>reverseAdj(n);
          
          for(int u = 0 ;  u < n; u++)
          {
              for(int &v : adj[u])
              {
                  reverseAdj[v].push_back(u);
              }
          }
          
          
          int ans = 0;
          visited = vector<bool>(n,false);
          // Step 3. Count the SCC Based on the number of DFS calls we are making.
          while(!st.empty())
          {
              int top = st.top();
              st.pop();
              
              if(!visited[top])
              {
                  DFS(reverseAdj,visited,top);
                  ans++;
              }
          }
          
          return ans;
          
      }
  };


Where Is This Useful?
1. Deadlock Detection in Operating Systems
In resource allocation graphs, cycles (strongly connected components) can indicate potential deadlocks.

Kosaraju helps detect such cycles efficiently.

2. Optimizing Compilers
In compiler optimization (e.g., control flow graphs), SCCs help identify loops and invariant code motion.

These are crucial for improving runtime performance.

3. Software Package Management / Build Systems
In package dependencies or build pipelines, SCCs help detect circular dependencies.

You can’t build A without B and B without A → SCC shows the cycle clearly.

4. Social Network Analysis
In following/friend graphs (like on Twitter), SCCs can show communities where everyone interacts with each other.

Example: a group of users where everyone follows everyone else.

5. Web Crawling / Page Ranking
Web pages can be modeled as a directed graph of links.

Finding SCCs helps identify clusters of related or interlinked pages.

6. Model Checking / Static Analysis
In formal verification or static analysis of programs, control and data flow graphs are analyzed for loops, which often form SCCs.