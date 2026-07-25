class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1){
            if (nums[0] == target){
                return 0;
            }
            return -1;
        }
        int left = 0;
        int right = nums.size()-1;
        
        int i = (right - left)/2; 
        int num = nums[i]; 

        while (num != target){ //its two pointers
            // the break case?
            if (left+1 == right){
                if (nums[left] == target){
                    num = nums[left];
                    return left;
                } else if (nums[right] == target){
                    num = nums[right];
                    return right;
                } else {
                    return -1;
                }
            }

            i = ((right-left)/2 + left);
            num = nums[i];

            if (num > target){
                right = i;
            } else if ( num < target ){
                left = i;
            } else {
                return i;
            }
        }
        return i;

        // 0 2 3 4 5 6 7 8 90 100
        // 95
        // how do we detect if there are two options left
    }
};
