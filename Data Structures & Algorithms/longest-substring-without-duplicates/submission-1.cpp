

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r;
        int count = 0;
        int maxcount = 0;
        unordered_set<int> hash;
        
        for (int r = 0; r < s.size(); ++r){
            if (hash.find(s[r]) == hash.end()){
                hash.insert(s[r]);
            } else {
                while (hash.find(s[r]) != hash.end()){
                    hash.erase(s[l]);
                    ++l;
                }
                hash.insert(s[r]);
            }
            
            if (maxcount < hash.size()){
                maxcount = hash.size();
            }
        }
        return maxcount;
    }
};
