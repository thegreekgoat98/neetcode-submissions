class Solution {
public:
    vector<vector<int>>dp;
    int solve(int currIdx, int currSum, vector<int>&coins, int&amount)
    {
        if(currSum == amount)
            return 0;
        if(currSum > amount)
            return -1;
        if(currIdx == coins.size())
            return -1;

        if(dp[currIdx][currSum] != INT_MIN)
            return dp[currIdx][currSum];

        int pick = -1;
        if(coins[currIdx] <= amount - currSum) //to avoid overflow
        {
            pick = solve(currIdx, currSum+coins[currIdx], coins, amount);
            if(pick != -1)
                pick++;
        }
        
        int not_pick = solve(currIdx+1, currSum, coins, amount);

        if(pick == -1)
            return dp[currIdx][currSum] = not_pick;
        if(not_pick == -1)
            return dp[currIdx][currSum] = pick;

        return dp[currIdx][currSum] = min(pick, not_pick);
    }
    //////////////////////////////////////////////////
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        dp.resize(n, vector<int>(amount+1, INT_MIN));
        return solve(0, 0, coins, amount);
    }
};

// Recursive + memoization
// TC - O(n*amount)
// SC - O(n*amount)

// I know the solve() looks complex
