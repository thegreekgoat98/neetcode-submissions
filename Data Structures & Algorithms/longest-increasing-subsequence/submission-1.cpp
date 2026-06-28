class Solution {
public:
    vector<vector<int>>dp;
    int solve(int currIdx, int prevIdxIncreasing, vector<int>& nums)
    {
        if(currIdx == nums.size()) //reached end of the list
            return 0;

        if(prevIdxIncreasing != -1 && dp[currIdx][prevIdxIncreasing] != -1)
            return dp[currIdx][prevIdxIncreasing];

        //take
        int take = 0;
        if(prevIdxIncreasing == -1 || nums[currIdx] > nums[prevIdxIncreasing])
            take = 1 + solve(currIdx+1, currIdx, nums);
        
        //skip
        int skip = solve(currIdx+1, prevIdxIncreasing, nums);

        if(prevIdxIncreasing != -1)
            dp[currIdx][prevIdxIncreasing] = max(take, skip);

        return max(take, skip);
    }
    ////////////////////////////////////////
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, -1, nums);
    }
};

// Recursive + memoization

// TC - O(n^2)
// https://www.youtube.com/watch?v=DG50PJIx2SM&t=228s -- beauty - codestorywithMIK