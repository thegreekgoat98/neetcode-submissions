# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # solving this as Iw would solve for a Binary tree ignoring it as a BST
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root:
            return None
        if root.val == p.val or root.val == q.val:
            return root

        leftN: TreeNode = self.lowestCommonAncestor(root.left, p, q)
        rightN: TreeNode = self.lowestCommonAncestor(root.right, p, q)

        if leftN and rightN:
            return root
        
        # if both one node among p and q is found
        if leftN: 
            return leftN
        return rightN


# solved by seeign tutorial of codestorywithMIK
