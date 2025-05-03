class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
            int n = points.size();
            vector<vector<pair<int,int>>>adj(n);
    
    
            for(int i = 0  ; i< n ;i++)
            {
                for(int j = i+1; j<n;j++)
                {   
                    int x1 = points[i][0];
                    int y1 = points[i][1];
    
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int distance = abs(x1-x2) + abs(y1-y2);
    
                    adj[i].push_back({j,distance});
                    adj[j].push_back({i,distance});
                }
            }
    
            vector<bool>visited(n,false);
            int result = 0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
            pq.push({0,0});
    
            while(!pq.empty())
            {
                int distance = pq.top().first;
                int node = pq.top().second;
    
                pq.pop();
    
                if(visited[node]) continue;
                
                visited[node] = true;
                result += distance;   // This is important here add result only if it is not visited, made mistake while submitting solution.
    
                for(auto vec : adj[node])
                {
                    int neigh = vec.first;
                    int weight = vec.second;
    
                    if(visited[neigh] == false)
                    {
                        pq.push({weight,neigh});
                    }
    
                }
    
            }
            return result;
        }
    };


Time Complexity:
The time complexity of the provided solution is O(n² log n), where n is the number of points. This arises because:

Adjacency List Construction: O(n²) to compute and store all pairwise distances.

Prim's Algorithm with Priority Queue: Each edge (O(n²) total) is processed once, and each heap operation (insert/extract-min) takes O(log n) time, leading to O(n² log n) for this phase.

Space Complexity:
The space complexity is O(n²) due to storing the adjacency list for a complete graph.

