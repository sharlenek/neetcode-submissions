class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size()==3){
            if (nums[0] + nums[1] + nums[2] == 0){
                return {{nums[0], nums[1], nums[2]}};
            } else {
                return {};
            }
        }

        // -4 -1, -1, 0, 1, 2
        vector<vector<int>> threesum;
        sort(nums.begin(), nums.end());

        int j;
        int k;
        int l;
        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            j = nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while (left < right){
                k = nums[left];
                l = nums[right];
                if (j + k + l > 0){
                    --right;
                } else if (j + k + l < 0){
                    ++left;
                } else {
                    threesum.push_back({j, k, l});
                    ++left;
                    --right;
                    while (left < right && (nums[left] == nums[left-1])){
                        ++left;
                    }
                }

            }
        } 
        return threesum;
    }
};
