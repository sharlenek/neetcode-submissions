class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //im gonna brute force this first
        //frequency array
        //seems like sliding window, does that work with a frequency array?
        //maybe i can add and subtract from freq array, see if it equals zero
        // or i can just make two arrays

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int size = s1.size();

        if (size > s2.size()){
            return false;
        }

        for (char s : s1){
            ++freq1[s - 'a'];
        }

        for (int r = 0; r < size; ++r){
            ++freq2[s2[r] - 'a'];
        }

        for (int r = size; r < s2.size(); ++r){
            if (freq1 == freq2){
                return true;
            } else {
                //i need to add the new right, and remove the old left
                ++freq2[s2[r] - 'a'];
                --freq2[s2[r-size] - 'a'];
            }
        }

        return freq1==freq2;
   
    }
};
