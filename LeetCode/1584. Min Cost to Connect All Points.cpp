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



Follow-Up Interview Questions:

1.Why use Prim's algorithm instead of Kruskal's here?
    Prim's is efficient for dense graphs (like this complete graph). Kruskal's has similar asymptotic complexity here (O(n² log n)) but may perform worse due to sorting all edges.

2.How can you optimize Prim's algorithm for this problem?
    Use the "array-based" Prim's (without a heap). Maintain an array to track minimum distances to the MST, reducing time complexity to O(n²) for dense graphs.

3.What if n is very large (e.g., 10⁵ points)?
    The current approach becomes infeasible. Alternative methods leveraging geometric properties (e.g., Delaunay triangulation for Manhattan distance) would be needed, though this is a more advanced topic.

4.How does the Manhattan distance affect the MST compared to Euclidean?
    The MST structure depends on the distance metric. Manhattan distance uses grid-like paths, leading to different edge weights and potentially a different MST compared to Euclidean.

5.Explain the role of the priority queue in Prim's algorithm.
    It efficiently selects the next closest node to the MST. The min-heap ensures we always pick the edge with the smallest weight connecting the MST to non-MST nodes.