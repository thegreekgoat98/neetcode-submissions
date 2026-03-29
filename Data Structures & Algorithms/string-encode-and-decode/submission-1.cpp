class Solution {
public:
    // Encode --> length + # + word 
    string encode(vector<string>& strs) 
    {
        string encoded_string="";
        for(int i=0;i<strs.size();++i)
            encoded_string += to_string(strs[i].size()) + "#" + strs[i];

        return encoded_string;
    }

    vector<string> decode(string s) 
    {
        int n=s.size();
        vector<string>res;

        int i=0;

        while(i<n)
        {
            int j=i;

            while(s[j]!='#')
                j++;
            
            int len=stoi(s.substr(i,j-i));

            j++;

            string word=s.substr(j,len);

            res.push_back(word);
            i=j+len;
        }

        return res;
    }
};
