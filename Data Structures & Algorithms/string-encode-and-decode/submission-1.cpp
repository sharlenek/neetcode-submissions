class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }

        string encoded = "";
        for (const string &s : strs){
            // for every word, add the size#word
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;

    }

    vector<string> decode(string s) {
        //for the length of the encoded string
        vector<string> decoded;
        int i = 0;
        while (i < s.size()){
            int wordlength;
            int j = i;

            //find what index the number stops
            // "10#hellohello"
            // so j is 2?
            while (s[j] != '#'){
                j++;
            }

            //in c++ its position, length. 
            wordlength = stoi(s.substr(i, j-i)); //wordlength = 10
            //now read the word using word length. skip the #
            //make first pointer j+1. make the second one the length + j + 1

            i = j+1; //i = 3

            string word = s.substr(i, wordlength);
            decoded.push_back(word);

            j = wordlength + i; // j= 13, where the next word starts
            i = j; //make i the same
        }
        return decoded;
    }
};
