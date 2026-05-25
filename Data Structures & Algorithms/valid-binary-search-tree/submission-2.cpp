/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool solve(TreeNode* node, int minVal, int maxVal)
    {
        if(!node)
            return true;
        
        if(node->val <= minVal || node->val >= maxVal)
            return false;
        
        return solve(node->left, minVal, node->val) && solve(node->right, node->val, maxVal);
    }
    /////////////////////////////////
    bool isValidBST(TreeNode* root) 
    {
        return solve(root, INT_MIN, INT_MAX);
    }
};

// https://chatgpt.com/c/69ad141b-8d30-8321-a3a1-f1b670ae85d4 -- took idea