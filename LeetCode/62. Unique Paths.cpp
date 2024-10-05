/// --------------------------------------------------------------------------------------------------
// This solution will work but will give TLE on greater value of m, n.
int uniquePaths(int m, int n) {
        
        int ans = 0 ; 
        solve(0,0,ans,m,n);
        return ans;
    }


void solve(int i , int j,int m , int n, int &ans)
{
    if(i >= m || j >= n )
        return;

    if(i == m-1 && j == n-1)
    {
        ans++;
        return;
    }

    solve(i+1,j,m,n,ans);
    solve(i,j+1,m,n,ans);

}    
/// --------------------------------------------------------------------------------------------------