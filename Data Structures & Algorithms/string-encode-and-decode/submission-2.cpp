class Solution {
public:

    string encode(vector<string>& strs) {
        //need to know size of vector, size of each string
        string s = "";
        s += to_string(strs.size());
        s += ':';

        for (string x : strs){
            s += to_string(x.size());
            s += ';';
            s += x;
        }
        return s;
    }

    vector<string> decode(string s) {
        string subs;
        int size;
        int strsize;
        vector<string> decoded;
        int i = 0;

        while (s[i] != ':'){
            subs += s[i];
            ++i;
        }

        size = stoi(subs);
        subs = "";
        ++i;

        for (int j = 0; j < size; ++j){

            while (s[i] != ';'){
                subs += s[i];
                ++i;
            }

            strsize = stoi(subs);
            subs = "";
            ++i; //pass the ;

            for (int k = 0; k < strsize; ++k){
                //the actual word
                subs += s[i];
                ++i;
            }
            decoded.push_back(subs);
            subs = "";
        }
        return decoded;
    }
};
