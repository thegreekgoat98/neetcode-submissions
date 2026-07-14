class Solution {
public:
    int m,n;
    vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<int>>&grid)
    {
        if(i == m || j == n)
            return 0;
        if(grid[i][j] == 1) //obstacle
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == m-1 && j == n-1)
            return 1;

        int right = solve(i, j+1, grid);
        int down = solve(i+1, j, grid);

        return dp[i][j] = right + down;
    }
    /////////////////////////////////////////////////////////////
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        dp.resize(m, vector<int>(n, -1));
        return solve(0, 0, obstacleGrid);
    }
};

// rec + memoized
// TC - O(m*n)
// stack depth - O(m+n)
// aux space - O(n*m)