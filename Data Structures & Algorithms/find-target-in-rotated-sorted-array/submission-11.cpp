class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;

        while (left <= right){
            mid = left + (right-left)/2;

            if (nums[mid] == target){
                return mid;
            }
            // 1 2 3 4 5
            // 5 1 2 3 4
            // 3 4 5 6 0 1 2
            // 3 4 5 1 2

            // 1 3 5
            

            // 1 3
            // conditions for a rotation. right < mid < left.
            // normal is left < mid < right

            if (nums[left] <= nums[mid]){
                if (target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
