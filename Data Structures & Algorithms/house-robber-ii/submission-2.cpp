class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums, int currIdx, int end)
    {
        if(currIdx > end)
            return 0;
        if(dp[currIdx] != -1)
            return dp[currIdx];

        int pick = nums[currIdx] + solve(nums, currIdx + 2, end);
        int not_pick = solve(nums, currIdx + 1, end);

        return dp[currIdx] = max(pick, not_pick);
    }
    /////////////////////////////////////////
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n == 1)
            return nums[0];
        dp.resize(n, -1);
        int case1 = solve(nums, 0, n-2); //include first index, exclude last index

        dp.assign(n, -1);
        int case2 = solve(nums, 1, n-1); //exclude first index, include last index

        return max(case1, case2);
    }
};

//rec + memo
// TC - O(n)
