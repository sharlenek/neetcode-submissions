class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #binary search but i have to find the rotation point
        #check left to middle to right

        left = 0
        right = len(nums)-1


        while left <= right:
            index = (right+left)//2

            if nums[index] == target:
                return index
            
            #left side is sorted
            if nums[left] <= nums[index]:
                if nums[left] <= target < nums[index]:
                    right = index-1  
                #its in the unsorted side (right)
                else:
                    left = index+1
            #right side is sorted
            else:
                if nums[index] < target <= nums[right]:
                    left = index+1
                else:
                    right = index-1
            
        return -1



        
        