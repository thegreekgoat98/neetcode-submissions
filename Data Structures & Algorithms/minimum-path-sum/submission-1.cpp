class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<int>>&grid)
    {
        if(i == n || j == m) // out of bound
            return 1e9;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == n-1 && j == m-1)
            return grid[i][j];

        int rightSum = grid[i][j] + solve(i, j+1, grid);
        int downSum = grid[i][j] + solve(i+1, j, grid);

        return dp[i][j] = min(rightSum, downSum);
    }
    ////////////////////////////////////////
    int minPathSum(vector<vector<int>>& grid) 
    {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n, vector<int>(m, -1));
        return solve(0, 0, grid);
    }
};

// rec + mem
// TC - O(m*n)
// stack space - O(m+n)