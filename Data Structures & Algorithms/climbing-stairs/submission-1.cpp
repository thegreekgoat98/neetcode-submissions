class Solution {
public:
    vector<int>dp;
    int solve(int n)
    {
        // base case
        if(n<0)
            return 0;
        if(n==0) // we reached 
            return 1;

        if(dp[n] != -1)
            return dp[n];

        // recursive logic
        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return dp[n] = one_step + two_step;
    }
    /////////////////////////////
    int climbStairs(int n) 
    {
        dp.resize(n+1, -1);
        return solve(n);
    }
};
