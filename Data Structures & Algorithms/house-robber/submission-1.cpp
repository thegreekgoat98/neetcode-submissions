class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums, int currIdx)
    {
        if(currIdx >= nums.size())
            return 0;
        
        if(dp[currIdx] != -1)
            return dp[currIdx];
        int pick = nums[currIdx] + solve(nums, currIdx + 2);
        int notPick = solve(nums, currIdx + 1);

        return dp[currIdx] = max(pick, notPick);
    }
    ////////////////////////////
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int currIdx = 0;
        dp.resize(n, -1);
        return solve(nums, currIdx);
    }
};

// Recursive + memo
//TC - O(n)

//dp[i] --> maximum amount of money that can be robbed starting from index i
