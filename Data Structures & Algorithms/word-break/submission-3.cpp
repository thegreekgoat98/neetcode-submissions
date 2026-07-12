class Solution {
public:
    int n;
    unordered_set<string>S;

    vector<int>dp;
    bool solve(int idx, string &s)
    {
        if(idx == n)
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        if(S.find(s) != S.end())
            return true;
        
        for(int l = 1; idx + l <= n; ++l)
        {
            string temp = s.substr(idx, l);
            if(S.find(temp) != S.end() && solve(idx+l, s))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }
    ////////////////////////////////////////////////////
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        n = s.size();
        for(string&word: wordDict)
            S.insert(word);

        dp.resize(n, -1);
        return solve(0, s);
    }
};

// recursive approach 
// beautiful explanation - codestorywithMIk - https://www.youtube.com/watch?v=oBUpyPZ08zU
//  TC - O(2^n)