class Solution {
    public:
      void floydWarshall(vector<vector<int>> &grid) {
         int n = grid.size(); // number of nodes
         
         for(int via = 0 ; via < n;via++)
         {
             for(int i = 0 ; i <n ; i++)
             {
                 for(int j = 0  ; j<n ;j++)
                 {
                  //   if(dist[i][j] == 1e8)
                  //         continue;
                          
                  //   if(dist[i][j] > dist[i][via] + dist[via][j])
                  //   {
                  //       dist[i][j] = dist[i][via] + dist[via][j];
                  //   }
                  if(grid[i][via] == 100000000 || grid[via][j] == 100000000) { // It is causing interger overflow when 10^8 + anything is happening
                      continue;
                  }
                  grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                 }
             }
         }
         return;
          
      }
  };


1. Key Concepts to Remember
Purpose: Finds the shortest paths between all pairs of nodes in a weighted graph (handles negative edges but not negative cycles).

Approach: Dynamic Programming. Iteratively improve shortest path estimates using intermediate nodes (via).

Infinity Handling: Use a large value (e.g., 1e9 or INT_MAX) to represent unreachable nodes, but avoid overflow during arithmetic.

Negative Cycles: After running the algorithm, if any diagonal cell dist[i][i] < 0, the graph contains a negative cycle.

Order of Loops: The outer loop must iterate over via (intermediate nodes), followed by i (source) and j (destination).



2. Common Interview Questions
Basic Implementation:

Given a graph, compute all-pairs shortest paths.

Handle negative edges and detect negative cycles.

Infinity Handling:

How to avoid integer overflow when adding large values (e.g., INF + INF)?

Solution: Skip updates if either dist[i][via] or dist[via][j] is infinity.

Negative Cycle Detection:

How to modify the algorithm to check for negative cycles?

Solution: After running Floyd-Warshall, check if dist[i][i] < 0 for any node i.

Comparison with Other Algorithms:

When to use Floyd-Warshall vs. Dijkstra/Bellman-Ford?

Answer: Floyd-Warshall is optimal for dense graphs (all-pairs), while Dijkstra/Bellman-Ford are better for single-source.

Path Reconstruction:

How to reconstruct the shortest path between two nodes?

Solution: Maintain a next matrix to track the next node in the path.