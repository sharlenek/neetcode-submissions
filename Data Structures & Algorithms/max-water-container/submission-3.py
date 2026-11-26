class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights)-1
        maxheight = 0

        while (left < right):
            height = min(heights[left], heights[right]) * (right-left)
            if (height>maxheight):
                maxheight = height

            if heights[left] < heights[right]:
                left+=1
            else:
                right-=1
        
        return maxheight
            
        