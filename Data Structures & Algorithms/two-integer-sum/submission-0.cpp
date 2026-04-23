class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        int find;
        for (int i = 0; i < nums.size(); ++i){
            find = target - nums[i];
            if ( hashmap.count(find) == 1 ){
                return {hashmap[find], i};
            }
            hashmap[nums[i]] = i; 

       } 
       return {};
    }
};
