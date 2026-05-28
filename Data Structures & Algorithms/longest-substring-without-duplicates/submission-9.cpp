

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r;
        int count = 0;
        int maxcount = 0;
        unordered_map<char, int> hash;
        
        for (int r = 0; r < s.size(); ++r){
            if (hash.find(s[r]) != hash.end()){
                if (l <= hash[s[r]]){
                    l = hash[s[r]] + 1;
                }
            }
            hash[s[r]] = r;
            count = r - l + 1;
            if (maxcount < count){
                maxcount = count;
            }
        }
        return maxcount;
    }
};
