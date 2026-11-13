class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); ++i){
            //key is number, value is frequency
            hash[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>> minheap;

        for (auto pair : hash){
            int value = pair.first;
            int freq = pair.second;

            minheap.push({freq, value});

            if (minheap.size() > k){
                minheap.pop();
            }

        }

        vector<int> result;
        while (!minheap.empty()){
            result.push_back(minheap.top().second);
            minheap.pop();
        }

        return result;
    }
};
