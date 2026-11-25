class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #binary search, need to keep track of left and right
        #when left = right or something like that then i break and return false

        left = 0
        right = len(nums)-1

        while left <= right:
            index = (right+left)//2

            if nums[index] > target:
                right = index-1
            elif nums[index] < target:
                left = index+1
            else:
                return index
    
        return -1
        