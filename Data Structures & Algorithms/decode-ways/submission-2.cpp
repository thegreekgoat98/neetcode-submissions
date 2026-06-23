class Solution {
public:
    vector<int>dp;
    int solve(int currIdx, string&s)
    {
        if(dp[currIdx] != -1)
            return dp[currIdx];

        if(currIdx == s.size())
            return dp[currIdx] = 1;
        
        if(s[currIdx] == '0')
            return dp[currIdx] = 0;
        
        int result = solve(currIdx+1, s); //consider one digit

        if(currIdx+1 < s.size())
        {
            if(s[currIdx] == '1' || (s[currIdx] == '2' && s[currIdx+1] <= '6'))
                result += solve(currIdx+2, s); //consider two digits
        }

        return dp[currIdx] = result;
    }
    //////////////////////////////////////
    int numDecodings(string s) 
    {
        int n=s.size();
        dp.resize(n+1, -1);

        return solve(0, s);
    }
};

// Recursive + memoization
// TC - O(n)
