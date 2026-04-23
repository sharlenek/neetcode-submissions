class Solution {
public:
    bool isAnagram(string s, string t) {
        //use a hashmap and compare instances?
        //i can either make two hashmaps, or make one? and then see if
        //if the numbers are even or odd? it has to be even
        //i can also compare size of strings
        //actually i cant ill just make two

        if (s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        for (int i = 0; i < s.length() ; i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        if (smap == tmap){
            return true;
        }
        return false;
    }
};
