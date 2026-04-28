class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //brute force? wait or compare to each array
        //make a separate array for first one then compare each one to first one
        //make hashmap where key is sorted version and values are the strings
        //im gna copy code i had for anagram
        //or lowk i could sort?
        //hashmap?

        
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> hash;
        string sorted;

        for (int i = 0; i < strs.size(); ++i){
            sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());
            hash[sorted].push_back(strs[i]);
        }
        for (auto const& [key, val] : hash) {
            anagrams.push_back(val);
        }
        return anagrams;
    }
};
