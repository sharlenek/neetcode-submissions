class Solution {
public:
    int characterReplacement(string s, int k) {
        // time to use a frequency array
        vector<int> freq(26, 0);
        int l = 0;
        int maxf = 0;
        int ascii;
        int result = 0;

        for (int r = 0; r < s.size(); ++r){
            ascii = s[r] - 'A';
            ++freq[ascii];

            if (freq[ascii] > maxf){
                maxf = freq[ascii];
            }

            if ((r - l + 1) - maxf <= k){
                if (r - l + 1 > result){
                    result = r - l + 1;
                }
            } else {
                while ((r - l + 1) - maxf > k){
                    --freq[s[l] - 'A'];
                    ++l;
                }
            }

        }
        return result;

    }
};
