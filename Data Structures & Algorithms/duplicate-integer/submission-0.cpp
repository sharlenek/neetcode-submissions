class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i ++){
            if (hashmap.count(nums[i]) == 1){
                return true;
            }
            hashmap[nums[i]] = i;
        }
        return false;
    }
};