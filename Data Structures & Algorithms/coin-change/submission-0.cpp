class Solution {
public:
    int solve(int currIdx, int currSum, vector<int>&coins, int&amount)
    {
        if(currSum == amount)
            return 0;
        if(currSum > amount)
            return -1;
        if(currIdx == coins.size())
            return -1;
        
        int pick = solve(currIdx, currSum+coins[currIdx], coins, amount);
        if(pick != -1)
            pick++;
        
        int not_pick = solve(currIdx+1, currSum, coins, amount);

        if(pick == -1)
            return not_pick;
        if(not_pick == -1)
            return pick;

        return min(pick, not_pick);
    }
    //////////////////////////////////////////////////
    int coinChange(vector<int>& coins, int amount) 
    {
        return solve(0, 0, coins, amount);
    }
};

// Recursive
// TC - O(2^(n+amount))
// SC - O(amount)
