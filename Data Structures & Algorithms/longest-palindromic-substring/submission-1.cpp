class Solution {
public:
    vector<vector<int>>dp;
    bool isPalindrome(string &s, int i, int j)
    {
        if(i >= j)
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = isPalindrome(s, i+1, j-1);
        return dp[i][j] = false;
    }
    /////////////////////////////////////
    string longestPalindrome(string s) 
    {
        int n=s.size();

        dp.resize(1001, vector<int>(1001, -1));

        int startIdx = 0;
        int maxLen = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                if(isPalindrome(s, i, j))
                {
                    if(j-i+1 > maxLen)
                    {
                        startIdx = i;
                        maxLen = max(maxLen, j-i+1);
                    }
                }
            }
        }
        // cout<<startIdx<<maxLen;
        return s.substr(startIdx, maxLen);
    }
};

//rec + memo
// TC - O(n^3)
