class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() <= 1){
            return false;
        }

        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                st.push(s[i]);
            } else {
                if (st.empty()){
                    return false;
                }
                char x = st.top();
                st.pop();
                if (s[i] == ')'){
                    if (x != '('){
                        return false;
                    }
                } else if (s[i] == '}'){
                    if (x!='{'){
                        return false;
                    }
                } else if (s[i] == ']'){
                    if (x != '['){
                        return false;
                    }
                }
            }
        }

        if (!st.empty()){
            return false;
        }
        return true;
    }
};
