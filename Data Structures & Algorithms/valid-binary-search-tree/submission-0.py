# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        #depth?
        #i need to keep track of what the lowest or highest it can be
        return self.dfs(root, float('-inf'), float('inf'))

    def dfs(self, node, lower, upper) -> bool:
        if not node:
            return True

        if node.val >= upper or node.val <= lower:
            return False

        return self.dfs(node.left, lower, node.val) and self.dfs(node.right, node.val, upper)

        


            



        
        