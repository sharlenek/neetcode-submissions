class Solution {
public:
    int findMin(vector<int> &nums) {
        //binary search
        //but its not sorted maybe i move the side thats higher

        int left = 0;
        int right = nums.size()-1;

        int curr;
        int min = nums[0];

        while (left <= right){
            curr = left + (right-left)/2;

            if (nums[curr] < min){
                min = nums[curr];
            }

            if (nums[curr] < nums[right]){
                right = curr - 1;
            } else {
                left = curr + 1;
            }
        }
        return min;
    }
};
