# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.count = 0
        def solve(node, maxVal) -> None:
            if not node:
                return
            
            if node.val >= maxVal:
                self.count += 1
            
            solve(node.left, max(maxVal, node.val))
            solve(node.right, max(maxVal, node.val))


        solve(root, root.val)

        return self.count


# khud solve kiya pura