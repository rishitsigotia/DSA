class Solution {
    public:
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          vector<int>result(V,1e8);
          
          result[src] = 0;
          
          for(int i = 1 ; i<= V-1;i++)
          {
              for(auto &edge:edges) // Relaxation code.
              {
                  int u = edge[0];
                  int v = edge[1];
                  int wt = edge[2];
                  
                  if(result[u] != 1e8 && result[u] + wt < result[v])
                  {
                      result[v] = result[u] + wt;
                  }
                  
              }
          }
          //negative cycle weight  Agr ek br orr relax hogya to negative cycle hai
          for(auto edge:edges) // Relaxation code.
          {
              int u = edge[0];
              int v = edge[1];
              int wt = edge[2];
              
              if(result[u] != 1e8 && result[u] + wt < result[v])
              {
                 return {-1};
              }
              
          }
          return result;
          
      }
  };