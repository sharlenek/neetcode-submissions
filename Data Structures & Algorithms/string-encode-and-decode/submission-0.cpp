class Solution {
public:

    string encode(vector<string>& strs) {
        string combined = to_string(strs.size());
        combined.append("#");

        for (int i = 0; i < strs.size(); ++i){
            combined += to_string(strs[i].size()) + "," + strs[i];
        }
        return combined;
    }

    vector<string> decode(string s) {
        vector<string> separated;

        
        int intlength;

        string wordcount;
        int wc;

        string word = "";

        while (s[0]!= '#'){
            wordcount.push_back(s[0]);
            s.erase(0,1);
        }
        s.erase(0,1);
        wc = stoi(wordcount);

        for (int i = 0; i < wc; ++i){
            string length = "";
            while (s[0]!= ','){
                length.push_back(s[0]);
                s.erase(0,1);
            }
            s.erase(0,1);
            intlength = stoi(length);

            for (int j = 0; j < intlength; ++j){
                word.push_back(s[0]);
                s.erase(0, 1);
            }
            separated.push_back(word);
            word = "";
        }
      return separated;  
    }
};
