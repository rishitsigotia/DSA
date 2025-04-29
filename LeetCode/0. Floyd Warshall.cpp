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