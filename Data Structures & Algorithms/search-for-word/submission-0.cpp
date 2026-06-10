class Solution {
public: 
    vector<pair<int,int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool dfs(int i,int j, vector<vector<char>>& board, string word, int currIdx)
    {
        if(currIdx == word.size())
            return true;
        if(i < 0 || i>=board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[currIdx])
            return false;

        char ch = board[i][j];
        board[i][j] = '.';

        bool ans = false;
        for(auto&it : dir)
            ans = ans || dfs(i+it.first, j+it.second, board, word, currIdx+1);

        board[i][j] = ch;

        return ans;
    }
    //////////////////////////////////////////////////////
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(board[i][j] == word[0])
                    if(dfs(i, j, board, word, 0))
                        return true;
            }
        }

        return false;
    }
};
