class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = 1;
        suffix[nums.size()-1] = 1;
        
        // 2 2 3 4
        //need to multiply the number before with all the numbers before it.
        //do i need one array or two?
        for (int i = 1; i < nums.size(); ++i){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        // 1 2 4 12

        //now i need to multiply it with everything after
        // 24 12 4 1
        for (int i = nums.size()-2; i >= 0; --i){
            suffix[i]= suffix[i+1] * nums[i+1];
        }

        for (int i = 0; i < nums.size(); ++i){
            output[i] = suffix[i] * prefix[i];
        }
        return output;

    }
};
