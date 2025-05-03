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