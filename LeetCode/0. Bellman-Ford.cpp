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



1. Time Complexity
Worst Case: O(V × E)

V-1 Relaxation Passes: Each pass processes all E edges.

Negative Cycle Check: One additional pass (O(E)).

Best Case: Still O(V × E) (no early termination).

Space Complexity: O(V) (for storing distances).

2. Key Points to Remember for Interviews
✅ Works with Negative Weights (unlike Dijkstra).
✅ Detects Negative Cycles (unlike Dijkstra or Floyd-Warshall).
✅ Slower than Dijkstra (Dijkstra is O(E + V log V) with a priority queue).

⚠ Edge Cases to Handle:

Disconnected Graphs: Some nodes may remain INT_MAX.

Negative Cycles:

If reachable from source → shortest paths are undefined (return -1).

If unreachable → ignore and return distances.

Large Weights/Overflows: Use INT_MAX carefully to avoid integer overflow.

3. Optimizations (Mention in Interview)
🔹 Early Termination: If no relaxation occurs in a pass → stop early.
🔹 SPFA (Shortest Path Faster Algorithm): A queue-based optimization (but worst-case remains O(V×E)).

4. When to Use Bellman-Ford?
Negative weights present.

Need to detect negative cycles.

Dense graphs where Dijkstra’s priority queue overhead is high.

5. Sample Interview Question
"Given a directed graph with possible negative weights, find the shortest path from node S to all other nodes or detect a negative cycle."

Answer Structure: