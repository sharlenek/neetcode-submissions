# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        #if the trees have the same structure
        #check the nulls
        #check the values
        #iterative? return false and only return true at the end
        if not p and not q:
            return True

        if not p or not q:
            return False

        stack = [(p, q)]
        while stack:
            left, right = stack.pop()
            if not left and not right:
                continue
            
            if not left or not right:
                return False

            if left.val != right.val:
                return False

            stack.append((left.left, right.left))
            stack.append((left.right, right.right))
        
        return True;

            




        