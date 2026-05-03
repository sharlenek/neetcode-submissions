class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int min;
        vector<int> topk;
        unordered_map<int, int> hash;
        vector<vector<int>> twod(nums.size()+1);

        //filling up hashmap
        for (int i = 0; i < nums.size(); ++i){
            hash[nums[i]]++; 
            //key is the number
            //value is the num of occurences
        }

        //moving hashmap into 2d array
        for (auto const& [key, val] : hash){
            twod[val].emplace_back(key);
            //use the num of occurences as the index
            //push back the actual number
        }
        //now use 2d array to return top k elements
        int count = 0;
        for (int i = twod.size()-1; i > 0; --i){
            if (!(twod[i].empty())){
                for (int j = 0; j < twod[i].size(); j++){
                    if (count < k){
                        topk.emplace_back(twod[i][j]);
                        count++;
                    } else {
                        break;
                    }
                }
            }
        }
        return topk;

    }
};
