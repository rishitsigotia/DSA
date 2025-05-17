vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //This question is purely based on Eulier Path concepts 
        // Prerequisites are Eulier  concepts like 
        //What should be the starting node , whose outDegree[node] - inDegree[node] = 1
        // Break the questions in step.

        //Step 1. Build AdjList
        unordered_map<int, vector<int>> adj;
        //build  indegree and outdegree
        unordered_map<int, int> inDegree, outDegree;
        //key - node
        //value - indegree/outdegree

        for(auto edges:pairs)
        {
            int u = edges[0];
            int v = edges[1];

            adj[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        //Step 2. Choose Start Node

        int startNode;

        for(auto it:adj)
        {
            int node = it.first;

            if(outDegree[node] - inDegree[node] == 1)
            {    
                startNode = node;
                break;
            }
        }
        
        //Step 3. Do the DFS
        vector<int> EulerPath; //to store my eulerpath
        stack<int> st; //to perform dfs

        st.push(startNode);

        while(!st.empty()) 
        {
            int curr = st.top();
            if(!adj[curr].empty()) {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }

        //Build your result
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> result;
        for(int i = 0; i < EulerPath.size()-1; i++) 
        {
            result.push_back({EulerPath[i], EulerPath[i+1]});
        }
        return result;
    }