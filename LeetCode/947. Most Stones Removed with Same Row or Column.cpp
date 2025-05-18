// This question is solved by DFS but it is more likely to be understood by math.
// As the code is very less line but logic is more important why we are returing n - groups


//Suppose There are n stones
 ✅ Key Insight:
// You cannot remove all stones from a connected component (i.e., a group of stones connected via row/column).

// In each such group, you must leave at least one stone behind — the last one that has no more connections to any other.

// So in each group:

// If you have x stones, you can remove x - 1 stones.

🧮 Math Behind It:
// Let’s say there are G1, G2, ..., Gk groups of stones with:

// x1, x2, ..., xk stones in them respectively.
// Total Stones = x1 + x2 + ... + xk = n
// Max Stones Removed = (x1 - 1) + (x2 - 1) + ... + (xk - 1)
//                    = (x1 + x2 + ... + xk) - k
//                    = n - k
// Where k is the number of connected groups.


📌 Analogy (for Intuition):
// Imagine stones as people standing in rows and columns. If a person is alone in their row and column, they can't be removed (no "friend" to swap with). But in any group, all but one can be removed — the last one has no one left to swap with.


class Solution {
    void DFS(vector<vector<int>>& stones,int index, vector<bool>&visited)
    {
        visited[index] = true;

        int row = stones[index][0];
        int col = stones[index][1];

        for(int i = 0 ;  i< stones.size();i++)
        {
            if(!visited[i] && (stones[i][0] == row || stones[i][1] == col))
            {
                DFS(stones,i,visited);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); // number of stoens;

        vector<bool>visited(n,false);
        int groups = 0 ;
        for(int i = 0 ; i <n ;i++)
        {   
            if(visited[i])
                continue;
            
            DFS(stones,i,visited);
            groups++;

        }

        return n - groups;
    }
};