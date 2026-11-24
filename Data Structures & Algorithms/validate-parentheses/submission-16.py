class Solution:
    def isValid(self, s: str) -> bool:
        hashmap = {'(':')', '{':'}', '[':']'}
        if len(s)%2 != 0:
            return False

        stack = []

        for char in s:
            if char in hashmap:
                stack.append(char)
            else:
                if len(stack) == 0 or char != hashmap[stack.pop()]:
                    return False
        
        if len(stack) > 0:
            return False
        return True

                
        