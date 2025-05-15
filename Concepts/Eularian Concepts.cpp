class Solution {
  public:
    void DFS(int u, vector<bool> &visited,vector<int> adj[] )
    {
        visited[u] = true;
        
        for(int &v: adj[u])
        {
            if(!visited[v])
                DFS(v,visited,adj);
        }
    } 
    
    bool isConnected(int V, vector<int> adj[])
    {
        // Take any nonZeroDegree node
        int nonZeroDegree = -1;
        vector<bool>visited(V,false);
        for(int i = 0 ; i< V; i++)
        {
            if(adj[i].size() != 0)
            {    
                nonZeroDegree = i;
                break;
            }
        }
        
        //Now do DFS so all the connected nodes will be marked visited, if not visited means we have disconneted componenent;
        DFS(nonZeroDegree,visited,adj);
        
        for(int i = 0 ; i < V; i++)
        {
            if(!visited[i] && adj[i].size() > 0)
                return false;
        }
        return true;
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        
     // Step 1
      // IF non-zero degree wale are disconnected then kabhi Euler Path ni hoga
      if(!isConnected(V,adj))
        return 0;
        
    
    //Step 2 check oddDegreeCound as per the concept if we have Eulian Circuit we have no odd degeree only even degree.
    // if We have eulian path we have 2 odd degree
     int oddDegreeCount = 0;
     
     for(int i = 0 ; i <V ; i++)
     {
         if(adj[i].size() % 2  != 0)
            oddDegreeCount++;
     }
     
     if(oddDegreeCount >2)
        return 0;
    else if (oddDegreeCount == 2)
        return 1;
    
    return 2;
        
    }
};